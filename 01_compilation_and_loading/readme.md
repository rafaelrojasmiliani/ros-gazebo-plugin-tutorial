# Description
This folder contains an example of how to create and compile an elementary World Plugin for Gazebo.
This World Plugin prints a message when the Gazebo World is created.

**How to build this plugin** run `build_plugin.bash` in this folder.

**How to run the examples** run `run_example.bash`.

1. Creation of a Gazebo World with a World Plugin associated to it.
2. Creation of a plugin. The class is created inheriting from the base Gazebo World Plugin class and its `Load` method is defined.
3. Compilation of the plugin
4. Instruct Gazebo where the new plugin is available using the `GAZEBO_PLUGIN_PATH` environment variable.

## Creation of a World with a World Plugin

In order to associate a World Plugin with a Gazebo World it is only necessary to add the `plugin` tag in the content of the `world` element.
The minimum `sdf` file is
```XML
<?xml version="1.0"?>
<sdf version="1.4">
  <world name="default">
    <plugin name="pluging_name" filename="libplugin_sharedlibrary.so"/>
  </world>
</sdf>
```

## How to create a plugin class

There are 5 types of plugin base classes.
They inherit from the same template class `gazebo::PluginT` [declared here](https://github.com/osrf/gazebo/blob/67c43463c87685b7c9d485a9f8d2e6ac760815b9/gazebo/common/Plugin.hh#L75).


- `gazebo::ModelPlugin` A plugin with access to `physics::Model` i.e. the physical properties of models and their underlying elements (links, joints, collision objects).
- `gazebo::SensorPlugin` A plugin with access to `physics::Sensor`
- `gazebo::SystemPlugin ` A plugin loaded within the `gzserver` on startup.
- `gazebo::VisualPlugin` A plugin with access to `rendering::Visual`.
- `gazebo::WorldPlugin` A plugin with access to physics::World. It can be used to monitor the models in a running simulation, and insert new ones. It can be also used to modify the physics of the simulation.

In order to implement any kind of gazebo plugin it is necessary to inherit from any of the itemized classes and implement the `Load` method. The signatures of these `Load` methods are

- `gazebo::ModelPlugin::Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)`
- `gazebo::SensorPlugin::Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)`
- `gazebo::SystemPlugin::Load(int _argc = 0, char **_argv = nullptr)`
- `gazebo::VisualPlugin::Load(sensors::SensorPtr _sensor,sdf::ElementPtr _sdf)`
- `gazebo::WorldPlugin::Load(physics::WorldPtr _world,sdf::ElementPtr _sdf)` 

For all plugins but `SystemPlugin` the `Load` method is called when a Plugin is first created, and after the World has been loaded.

**Note:** The declaration of the different types of plugins types use the [curiously recurring template pattern](https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern).

## How to compile a plugin

Gazebo Plugins are stored in shared libraries that must be complied from a C program.
A minimum `CMakeLists.txt` file looks as follows
```CMake
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})

list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

add_library(library_name SHARED src/source_file.cpp)
target_link_libraries(library_name ${GAZEBO_LIBRARIES})
```

## How to instruct Gazebo where to find the plugins

To tell Gazebo where the plugins are stored we have to assign this location to the `GAZEBO_PLUGIN_PATH` environment variable.
For example
```BASH
    export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:${package_directory}/lib
```
