
#include "mcu_walker.hpp"

mcu_walker::mcu_walker(float cpu_speed,int memory,std::string os,std::string nama,int volt,int motor_speed,int rotation) : MCU(cpu_speed, memory, os, nama, volt) {
    this->motor_speed = motor_speed;
    this->rotation = rotation;

    cout << "[KONSTRUKTOR WALKER] : Sistem gerak " << name << " telah diinisialisasi." << endl;
}

mcu_walker::~mcu_walker() {
    cout << "[DESTRUKTOR WALKER] : Komponen walker " << name << " telah dimatikan." << endl;
}

void mcu_walker::rotate(int rotation) {
    this->rotation = rotation;
    cout << "[WALKER] : " << name << " berputar ke arah " << rotation << " derajat." << endl;
}

void mcu_walker::increase_speed(int speed) {
    this->motor_speed += speed;
    cout << "[WALKER] : Kecepatan motor " << name << " naik menjadi " << motor_speed << " RPM." << endl;
}

void mcu_walker::showSpek() {
    cout << "[SPEK MCU_WALKER] : " << name << "\n"
         << "- CPU       : " << cpu_speed << " GHz\n"
         << "- RAM       : " << memory << " MB\n"
         << "- OS        : " << os << "\n"
         << "- Volt      : " << volt << " V\n"
         << "- Speed     : " << motor_speed << " RPM\n"
         << "- Rotation  : " << rotation << " Deg" << endl;
}

void mcu_walker::nambah_volt(int penambahan_voltase) {
    MCU::nambah_volt(penambahan_voltase);
}

void mcu_walker::ganti_os(std::string new_os) {
    this->os = new_os;
    cout << "[WALKER UPDATE] : " << name << " migrasi OS ke " << os << endl;
}