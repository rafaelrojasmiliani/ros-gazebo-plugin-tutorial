
#include <math.h>
#include <set_velocity.h>

namespace gazebo {
void SetVelocity::Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/) {

  model_ = _parent;

  // Listen to the update event. This event is broadcast every
  // simulation iteration.
  updateConnection_ = event::Events::ConnectWorldUpdateBegin(
      std::bind(&SetVelocity::OnUpdateBegin, this, std::placeholders::_1));
}

void SetVelocity::OnUpdateBegin(const common::UpdateInfo &_info) {
  const int32_t sec = _info.simTime.sec;
  const int32_t n_sec = _info.simTime.nsec;
  const double time =
      static_cast<double>(sec) + static_cast<double>(n_sec) * 1.0e-9;
  const ignition::math::Pose3d pose = model_->WorldPose();
  const double vx = 0.5 * pose.Pos().Y();
  const double vy = -0.5 * pose.Pos().X();
  const std::vector<physics::LinkPtr> &links = model_->GetLinks();
  cactor_onst std::vector<physics::JointPtr> &joints = model_->GetJoints();

  model_->SetLinearVel(ignition::math::Vector3d(vx, vy, 0.0));
  model_->SetAngularVel(ignition::math::Vector3d(0.0, 0.0, 0.0));
}
} // namespace gazebo
GZ_REGISTER_MODEL_PLUGIN(gazebo::SetVelocity)
