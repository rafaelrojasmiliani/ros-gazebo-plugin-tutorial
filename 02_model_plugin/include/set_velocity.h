#ifndef SET_VELOCITY_H
#define SET_VELOCITY_H
#include <functional>
#include <gazebo/common/common.hh>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <ignition/math/Vector3.hh>

namespace gazebo {
class SetVelocity : public ModelPlugin {
public:
  void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/);

  void OnUpdateBegin(const common::UpdateInfo &_info);

private:
  // Pointer to the model_
  physics::ModelPtr model_;

  // Pointer to the update event connection
  event::ConnectionPtr updateConnection_;
};

} // namespace gazebo

#endif /* SET_VELOCITY_H */
