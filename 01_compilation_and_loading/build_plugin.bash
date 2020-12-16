

main(){
    # This piece of code ensures that this script is called from its folder
    scriptdir=$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && pwd)
    if [ "$scriptdir" != "$(pwd)" ]; then
      echo "this script must be executed from $scriptdir".
      exit 1
    fi
    if [ ! -d "./build" ]; then
      mkdir build
    fi


    cd build && cmake ../ && make
}


main
