#include "mcu.hpp"
using namespace std;

void MCU::showSpek() {
    cout << "[BASE MCU] : " << name << " | CPU: " << cpu_speed 
         << "GHz | RAM: " << memory << "MB | OS: " << os 
         << " | Volt: " << volt << "V" << endl;
};

MCU::MCU(float cpu_speed,int memory,std::string os,std::string name,int volt) {
    this->cpu_speed = cpu_speed;
    this->memory = memory;
    this->os = os;
    this->name = name;
    this->volt = volt;

    cout << "[KONSTRUKTUR MCU] : Objek " << name << " berhasil dibuat." << endl;
}

MCU::~MCU() {
    cout << "[DESTRUKTOR MCU] : Objek base " << name << " dibersihkan." << endl;
}

void MCU::nambah_volt(int penambahan_voltase) {
    volt += penambahan_voltase;
    cout << "Voltase " << name << " berhasil dinaikkan ke: " << volt << "V" << endl;
}

void MCU::ganti_os(std::string new_os) {
    os = new_os;
}