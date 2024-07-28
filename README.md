# dockus

## Setup

`dockus` must be run as root, as only root is allowed certain syscalls.

You can add the `./dockus` shell script to the `PATH`, to both build and
run the executable as simply '`dockus`'.

```console
$ export PATH="$(pwd):$PATH"
```

You may also set `PS1` if it's not colored, or not showing the hostname.
This helps distinguish from the container:

```console
# PS1='\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
```

``` bash
docker export $(docker create alpine:latest) -o alpine_fs.tar.gz
```

## Demo

Every commit is a new step.

You can use [`git-slides`](https://github.com/qrichert/git-slides) to
navigate through the commits.

```console
$ git slides start
$ git slides next # or n
$ git slides previous # or p
$ git slides stop
```
