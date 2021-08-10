# dataSort

## Program Purpose:
Takes as arguments the name of a binary input file and a text output file. The binary input file contains 12 bit unsigned values. The output file contains the 32 largest numbers and the last 32 numbers read from the input file.

## Docker Image:
To build this image, type the following on a terminal inside the folder which contains the Dockerfile file:

**docker build -t gdb-cpp-image .**

Run the docker image with this command from cmd in windows to run gdb inside the docker image:

**docker run --rm -it --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -v /c/Users/username/Documents/Git/dataSort:/app -w /app gdb-cpp-image**

Now attach to the docker image with vs-code with the docker extension. Install whatever extensions you will want in the container itself.

