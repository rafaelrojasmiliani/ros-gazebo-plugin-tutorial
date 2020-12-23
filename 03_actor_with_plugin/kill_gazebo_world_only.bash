
main(){


    serverpid=$(ps ax | grep gzserver | grep -v grep | awk '{print $1}')
    clientpid=$(ps ax | grep gzclient | grep -v grep | awk '{print $1}')

    kill $clientpid
    sleep 0.5
    kill $serverpid
}

main

