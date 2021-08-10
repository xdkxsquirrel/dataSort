# dataSort

## Program Purpose:
Takes as arguments the name of a binary input file and a text output file. The binary input file contains 12 bit unsigned values. The output file contains the 32 largest numbers and the last 32 numbers read from the input file.

## Docker Image:
Sources: https://lemariva.com/blog/2020/10/vscode-c-development-and-debugging-containers
To build this image, type the following on a terminal inside the folder which contains the Dockerfile file:

**docker build -t gdb-cpp-image .**

The image will be built with a name gdb-cpp-image. To run a container based on this image so that VS Code can debug processes in it, type the following on a terminal inside the folder, in which your source code is located:

**docker run -d -p 2222:22 --security-opt seccomp:unconfined -v $PWD:/source --name gdb-cpp-image gdb-cpp-image**

The -d parameter detaches the Docker container from the terminal. The -p parameter links the port 2222 to the exposed 22 port of the container. As debugging requires running privileged operations, you'll run the container in unconfined mode, thus the --security-opt set to seccomp:unconfined. The -v parameter creates a bind mount that maps the local file system ($PWD - print working directory) into the container (/source). Therefore, you need to be inside the source code folder while you run this command, or you can change the $PWD value with a full path to the source directory.

### Building C in a container with VS Code:
First, let’s configure a building task. The task is usually defined in a tasks.json file inside the .vscode folder. Therefore, to configure/create it in a new project, press Ctrl+Shift+B and follow the prompts until you get to "Others" (see Fig. 1). If you have already a running project, you can create this file by yourself. Replace the content of the tasks.json with the following code:

**{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build-in-container",
            "type": "shell",
            "command": "/usr/bin/sshpass",
            "args": [
                "-p",
                "root",
                "ssh",
                "root@localhost",
                "-p",
                "2222",
                "/source/build.sh"
            ],
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}**

The label value tells VSCode that this is a building task (you can use another name) and the type defines that a command in the shell task. The command here is sshpass (which needs to be installed on your OS - sudo apt-get install sshpass). The arguments are passing the parameters to sshpass to login using ssh to the container with the correct password (root), port (2222) and the run script after the log-in (/source/build.sh). As you may have noticed, you need to create this build.sh file aside your source code. The content of that script reads as follows:

**mkdir -p /source/build && \\ \
cd /source/build && \\ \
cmake ../ -DCMAKE_BUILD_TYPE=Debug && \\ \
make -j4**

Don't remove the -DCMAKE_BUILD_TYPE=Debug flag, otherwise you won't be able to debug the compiled code.

You can see that this script just invokes CMake inside the /source/build directory, then builds the project. The trick is that we are invoking this via ssh inside the container. After this is set up, you can run a build at any time from within VSCode, as long as your container is running.

## Debugging C in a container with VS Code:
To bring up the Debug view, click the Run icon (Ctrl+Shift+D) in the Activity Bar and create a launch.json file and select the option C/C++: (gdb) from the prompt. The Pipe Launch configuration starts a tunnel using SSH to connect to a remote machine and pipe debug commands through. Replace the content of the launch.json with the following code:

**{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "build/app",
            "args": [],
            "stopAtEntry": true,
            "cwd": "/source",
            "environment": [],
            "externalConsole": true,  
            "sourceFileMap": { "/source": "${workspaceFolder}" },                       
            "pipeTransport": {
                "debuggerPath": "/usr/bin/gdb",
                "pipeProgram": "/usr/bin/sshpass",
                "pipeArgs": [
                    "-p",
                    "root",
                    "ssh",
                    "root@localhost",
                    "-p",
                    "2222"
                ],
                "pipeCwd": ""
            },           
            "MIMode": "gdb"         
        }
    ]
}**

As you may notice, the pipeTransport includes the same arguments as the task.json file. But this time, the absolute paths to the commands are required. The important lines to consider are the following:

- "cwd": "/source",: this is the workspace folder inside the container. In my case, I used the bind mounted folder.
- "program": "build/app",: this is a relative path to your executable/compiled application. This means, from the workspace folder, to the excecutable file. In my case the compiled file is located at /source/build/app inside the container. Thus, the the program variable reduces to build/app.
- "sourceFileMap": { "/source": "${workspaceFolder}" },: this is required to map the running application to the source code, so that you can create breakpoints on your code and you can check the variables. The /source path is inside the container, the ${workspaceFolder} is the absolute path to your code. VSCode replace the ${workspaceFolder} with the correct path.
Hit F5 to start debugging in the container. The provided launch.json is configured to break on entry ("stopAtEntry": true,) so you can immediately see that it is working.
