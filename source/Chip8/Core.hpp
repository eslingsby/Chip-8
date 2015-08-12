#pragma once

#include <stdint.h>
#include <fstream>
#include "Output/Screen.hpp"

class Core{
	uint8_t _memory[512];

	uint8_t _screen[256];
	uint8_t _font[80];
	uint8_t _var[16];
	uint8_t _key[16];

	uint16_t _pc;
	uint16_t _sp;
	uint16_t _i;

	uint16_t _delay;
	uint16_t _sound;

	uint16_t _length;

	void _tick();
	void _skip();
	void _jump(uint16_t& reg, uint16_t val);

	void _00E0();
	void _00EE();
	void _0NNN(uint16_t NNN);
	void _1NNN(uint16_t NNN);
	void _2NNN(uint16_t NNN);
	void _3XNN(uint8_t VX, uint8_t NN);
	void _4XNN(uint8_t VX, uint8_t NN);
	void _5XY0(uint8_t VX, uint8_t VY);
	void _6XNN(uint8_t VX, uint8_t NN);
	void _7XNN(uint8_t VX, uint8_t NN);
	void _8XY0(uint8_t VX, uint8_t VY);
	void _8XY1(uint8_t VX, uint8_t VY);
	void _8XY2(uint8_t VX, uint8_t VY);
	void _8XY3(uint8_t VX, uint8_t VY);
	void _8XY4(uint8_t VX, uint8_t VY);
	void _8XY5(uint8_t VX, uint8_t VY);
	void _8XY6(uint8_t VX, uint8_t VY);
	void _8XY7(uint8_t VX, uint8_t VY);
	void _8XYE(uint8_t VX, uint8_t VY);
	void _9XY0(uint8_t VX, uint8_t VY);
	void _ANNN(uint16_t NNN);
	void _BNNN(uint16_t NNN);
	void _CXNN(uint8_t VX, uint8_t NN);
	void _DXYN(uint8_t VX, uint8_t VY, uint8_t N);
	void _EX9E(uint8_t VX);
	void _EXA1(uint8_t VX);
	void _FX07(uint8_t VX);
	void _FX0A(uint8_t VX);
	void _FX15(uint8_t VX);
	void _FX18(uint8_t VX);
	void _FX1E(uint8_t VX);
	void _FX29(uint8_t VX);
	void _FX33(uint8_t VX);
	void _FX55(uint8_t VX);
	void _FX65(uint8_t VX);

public:
	Core();

	void reset();
	bool load(const char* filepath);

	void input(uint16_t keys);
	void update(float dt);
	void output(Screen& screen);

	bool operate(uint8_t lower, uint8_t upper);

	void print();
};