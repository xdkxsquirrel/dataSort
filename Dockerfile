FROM ubuntu
LABEL description="Visual Studio Code Ubuntu Container for Software Development"
RUN apt-get update -y 
RUN apt-get install -y build-essential
RUN apt-get install -y ruby-full
RUN gem install ceedling
