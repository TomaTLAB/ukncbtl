// Emulator.h

#pragma once

#include "emubase/Board.h"

//////////////////////////////////////////////////////////////////////


extern CMotherboard* g_pBoard;

extern BOOL g_okEmulatorRunning;

extern BYTE* g_pEmulatorRam[3];  // RAM values - for change tracking
extern BYTE* g_pEmulatorChangedRam[3];  // RAM change flags
extern WORD g_wEmulatorCpuPC;      // Current PC value
extern WORD g_wEmulatorPrevCpuPC;  // Previous PC value
extern WORD g_wEmulatorPpuPC;      // Current PC value
extern WORD g_wEmulatorPrevPpuPC;  // Previous PC value


//////////////////////////////////////////////////////////////////////

void Emulator_SetSound(BOOL enable);
BOOL Emulator_Init();
void Emulator_Done();
void Emulator_SetCPUBreakpoint(WORD address);
void Emulator_SetPPUBreakpoint(WORD address);
BOOL Emulator_IsBreakpoint();
void Emulator_Start();
void Emulator_Stop();
void Emulator_Reset();
int Emulator_SystemFrame();
float Emulator_GetUptime();  // UKNC uptime, in seconds

void Emulator_PrepareScreenRGB32(void* pBits, const DWORD* colors);

void Emulator_KeyEvent(BYTE keyPressed, BOOL pressed);
WORD Emulator_GetKeyEventFromQueue();
void Emulator_ProcessKeyEvent();

void Emulator_LoadROMCartridge(int slot, LPCTSTR sFilePath);

// Update cached values after Run or Step
void Emulator_OnUpdate();
WORD Emulator_GetChangeRamStatus(int addrtype, WORD address);

void Emulator_SaveImage(const QString &sFilePath);
void Emulator_LoadImage(const QString &sFilePath);


//////////////////////////////////////////////////////////////////////
