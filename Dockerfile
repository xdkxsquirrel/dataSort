FROM ubuntu
LABEL description="Visual Studio Code Ubuntu Container for Software Development"
RUN apt-get update
RUN apt-get install -y g++ build-essential make cmake gdb gdbserver rsync zip openssh-server git 
RUN apt-get install -y libopenblas-dev liblapack-dev python3-dev libncurses5-dev libncursesw5-dev libasio-dev libboost-all-dev
RUN apt-get install -y ruby-full
RUN gem install ceedling