#include "chip8.h"
#include <fstream>
void Chip8 :: initialize(){
    pc = 0x200; // program counter starts at 0x200
    I = 0;      // reset index register
    sp = 0;     // reset stack pointer
    delayTimer = 0; // reset delay timer
    soundTimer = 0; // reset sound timer
    for (int i = 0; i < 4096; ++i) {
        memory[i] = 0; // clear memory
    }
    for (int i = 0; i < 16; ++i) {
        V[i] = 0; // clear registers
    }
    for (int i = 0; i < 16; ++i) {
        stack[i] = 0; // clear stack
    }
    for (int i = 0; i < 64 * 32; ++i) {
        display[i] = 0; // clear display
    }
    for (int i = 0; i < 16; ++i) {
        keypad[i] = 0; // clear keypad
    }
    drawFlag = false; // reset draw flag
}
bool Chip8::loadROM(const std::string& path) {
    std::ifstream file(path,std::ios::binary);
        if (!file){
            return false;
        }
    int adress = 0x200;
    char byte;
    while (file.get(byte)){
        memory[adress] = byte;
        adress += 1; 

    }
    return true;
}
void Chip8::emulateCycle(){
    uint16_t opcode = ((memory[pc] << 8)|(memory[pc + 1]));
    pc += 2;
    switch(opcode >> 12){
        case 0x1:{
            uint16_t address = opcode & 0x0fff;
            pc = address;
            break;
        }
        case 0x6:{
            uint8_t x = (opcode >> 8 )& 0x0f;
            uint8_t kk = opcode & 0x00ff;
            V[x] = kk;
            break;
        }
        default:
            break;
    }

}