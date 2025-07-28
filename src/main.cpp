#include <Windows.h>
#include "input_display.h"

// Thread that runs our mod logic
DWORD WINAPI MainThread(LPVOID lpParam) {
    input_display::init();

    // Simple loop to keep thread alive for now
    while (true) {
        input_display::render();
        Sleep(10);
    }
    return 0;
}

// DLL entry point
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(hModule);
            CreateThread(nullptr, 0, MainThread, hModule, 0, nullptr);
            break;
        case DLL_PROCESS_DETACH:
            // Cleanup here if needed
            break;
    }
    return TRUE;
}

