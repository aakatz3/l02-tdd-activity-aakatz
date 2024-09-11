# --platform=linux/amd64 makes this work for Apple silicon, does it break for Windows or Linux?
FROM --platform=linux/amd64 ubuntu:jammy AS build-env

# Set environment variable to make sure non-interactive installations are done
ENV DEBIAN_FRONTEND=noninteractive

# Update package list and install necessary tools
RUN apt-get update && apt-get install -y \
    wget \
    ruby \
    build-essential \
    clang \
    ninja-build \
    gcc \
    git \
    curl \
    python3 \
    python3-pip \
    gdb \
    libcmocka0 libcmocka-dev  

# Get latest version of CMake
ENV version=3.30.2
RUN cd /tmp &&
    mkdir /opt/cmake && \
    wget https://github.com/Kitware/CMake/releases/download/v$version/cmake-$version-Linux-x86_64.sh && \
    chmod a+x ./cmake-$version-Linux-x86_64.sh && \
    ./cmake-$version-Linux-x86_64.sh --prefix=/opt/cmake --skip-license && \
    rm cmake-$version-Linux-x86_64.sh
ENV PATH="/opt/cmake/bin:${PATH}"


# Pull L02 TDD Activity
RUN cd /home && \
    git clone --recurse-submodules https://github.com/ese5180/l02-tdd-activity.git


# Set the default command to run when the container starts
CMD ["/bin/bash"]