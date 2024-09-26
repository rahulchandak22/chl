# Start from a minimal base image
FROM ubuntu:22.04

# Update and install necessary tools for running the binary
RUN dpkg --add-architecture i386 && apt-get update && apt-get install -y \
    xinetd \
    libc6:i386 \
    lib32gcc-s1 \
    lib32stdc++6 \
    gcc-multilib \
    file \
    && rm -rf /var/lib/apt/lists/*

# Create a directory for the CTF user and flag
RUN mkdir -p /home/ctf

# Add flag and challenge binary
COPY flag.txt /home/ctf/flag.txt
COPY challenge /home/ctf/challenge
COPY entrypoint.sh /home/ctf/entrypoint.sh
COPY xinetd /etc/xinetd.d/ctf

# Set permissions: flag only accessible by root
RUN chmod 444 /home/ctf/flag.txt
RUN chmod 555 /home/ctf/challenge
RUN chmod 555 /home/ctf/entrypoint.sh

# Create a low-privileged user
RUN useradd -m ctfuser && chown -R root:root /home/ctf

# Restrict the user's access
USER ctfuser
WORKDIR /home/ctf

# Disallow access to all binaries except for the challenge binary
EXPOSE 1337

# Use the custom entrypoint to run the challenge
ENTRYPOINT ["/home/ctf/entrypoint.sh"]
