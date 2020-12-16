

main(){

    scriptdir=$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && pwd)

    export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:${scriptdir}/build

    gzserver ${scriptdir}/world/hello.world --verbose
}

main
