
@ECHO OFF

docker build -t "ros_pluging_gazebo_tutorial" ^
    --build-arg myuser="%USERNAME%" ^
    --build-arg myuid=11011 ^
    --build-arg mygroup="%USERNAME%" ^
    --build-arg mygid=11011 ^
      -f ./image.dockerfile .
