
#ifndef GAZEBO_PLUGINS_ACTORPLUGIN_HH_
#define GAZEBO_PLUGINS_ACTORPLUGIN_HH_

#include <memory>
#include <ros/callback_queue.h>
#include <ros/ros.h>
#include <ros/subscribe_options.h>
#include <std_msgs/Float32MultiArray.h>
#include <string>
#include <tf/transform_broadcaster.h>
#include <thread>
#include <vector>

#include <gazebo/common/Plugin.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/util/system.hh>

namespace gazebo {
class GAZEBO_VISIBLE ActorPlugin : public ModelPlugin {
  /// \brief Constructor
public:
  ActorPlugin();

  /// \brief Load the actor plugin.
  /// \param[in] _model Pointer to the parent model.
  /// \param[in] _sdf Pointer to the plugin's SDF elements.
  virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf);

  /// \brief Function that is called every update cycle.
  /// \param[in] _info Timing information
private:
  void OnUpdate(const common::UpdateInfo &_info);

  ros::NodeHandlePtr rosNode;

  void get_ros_parameters(const ros::NodeHandlePtr);
  physics::ActorPtr actor_;
  physics::WorldPtr world_;
  ignition::math::Vector3d start_location_;
  std::vector<event::ConnectionPtr> connections_;
  common::Time last_update_;
  physics::TrajectoryInfoPtr trajectory_info_;
};
} // namespace gazebo
#endif
