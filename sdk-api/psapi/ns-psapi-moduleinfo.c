typedef struct _MODULEINFO {
  LPVOID lpBaseOfDll;
  DWORD  SizeOfImage;
  LPVOID EntryPoint;
} MODULEINFO, *LPMODULEINFO;