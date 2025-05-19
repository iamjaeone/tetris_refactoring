#pragma once

#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>

void sound_init(const char file_name);

void sound_play(const char* file_path);

void sound_stop(void);