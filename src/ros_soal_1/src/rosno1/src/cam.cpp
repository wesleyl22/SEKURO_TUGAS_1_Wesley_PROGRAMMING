#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class CamNode : public rclcpp::Node {
public:
    CamNode() : Node("cam_node"), count_(0) {
        publisher_ = this->create_publisher<std_msgs::msg::String>("vision_data", 10);
        
        timer_ = this->create_wall_timer(
            1000ms, std::bind(&CamNode::timer_callback, this));
    }

private:
    void timer_callback() {
        auto message = std_msgs::msg::String();
        message.data = "Deteksi Objek ke-" + std::to_string(count_++) + " : Kelapa";
        
        RCLCPP_INFO(this->get_logger(), "[Kamera] Mempublikasikan: '%s'", message.data.c_str());
        publisher_->publish(message);
    }
    
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CamNode>());
    rclcpp::shutdown();
    return 0;
}