# Deploying container on local system

To deploy the system on your localhost, run the following command.

```
docker build -t hsbc_ctf .
docker run -d -p 1337:1337 hsbc_ctf
```

After deploying the container you can access it by running this command.

```
nc localhost 1337
```

## Aliter

Alternatively, you can simply take a look at the `challenge` file and not worry about other files. Do note that the flag's path is hardcoded as an absolute one with respect to the container so you would get an error even with a `flag.txt` file in the CWD.
