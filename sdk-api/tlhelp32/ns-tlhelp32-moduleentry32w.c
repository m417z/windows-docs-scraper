typedef struct tagMODULEENTRY32W {
  DWORD   dwSize;
  DWORD   th32ModuleID;
  DWORD   th32ProcessID;
  DWORD   GlblcntUsage;
  DWORD   ProccntUsage;
  BYTE    *modBaseAddr;
  DWORD   modBaseSize;
  HMODULE hModule;
  WCHAR   szModule[MAX_MODULE_NAME32 + 1];
  WCHAR   szExePath[MAX_PATH];
} MODULEENTRY32W;