#include <functional>
#include <gazebo/common/common.hh>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <ignition/math/Vector3.hh>

namespace gazebo {
class UpdateMessage : public ModelPlugin {
public:
  void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/) {
    // Store the pointer to the model
    this->model = _parent;

    // Listen to the update event. This event is broadcast every
    // simulation iteration.
    this->updateConnection = event::Events::ConnectWorldUpdateBegin(
        std::bind(&UpdateMessage::on_update_begin, this));
  }

  // Called by the world update start event
  void on_update_begin() {
    // Apply a small linear velocity to the model.
    const double current_time = _info.simTime.Double();
    printf("The plugin was updated at %17.7E", current_time);
  }

private:
  // Pointer to the model
  physics::ModelPtr model;

  // Pointer to the update event connection
  event::ConnectionPtr updateConnection;
};

// Register this plugin with the simulator
} // namespace gazebo
