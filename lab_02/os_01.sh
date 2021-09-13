if [ -z "$1" ]; then
    echo "parameters not found"
    exit
fi

if ! [[ "$1" =~ ^[[:digit:]]+$ ]]; then
    echo "pid $1 not int"
    exit
elif ps -p $1 > /dev/null ; then
    echo "Name: $0"
    echo "pid: $1"
    echo "ppid: `ps -o ppid= -p $1`"

    if [ "$2" == "fd" ]; then
        echo fd: `ls -1 /proc/$1/fd`
    fi

else
echo "pid $1 not found"
exit
fi