

main(){

    scriptdir=$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && pwd)

    export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:${scriptdir}/build

    screen -S gzserver -d -m gzserver ${scriptdir}/world/example.world --verbose
    screen -S gzclient -d -m gzclient
}

main
