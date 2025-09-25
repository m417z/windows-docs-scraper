typedef struct _SP_DEVINSTALL_PARAMS_A {
  DWORD             cbSize;
  DWORD             Flags;
  DWORD             FlagsEx;
  HWND              hwndParent;
  PSP_FILE_CALLBACK InstallMsgHandler;
  PVOID             InstallMsgHandlerContext;
  HSPFILEQ          FileQueue;
  ULONG_PTR         ClassInstallReserved;
  DWORD             Reserved;
  CHAR              DriverPath[MAX_PATH];
} SP_DEVINSTALL_PARAMS_A, *PSP_DEVINSTALL_PARAMS_A;