typedef struct _SP_DEVINSTALL_PARAMS_W {
  DWORD             cbSize;
  DWORD             Flags;
  DWORD             FlagsEx;
  HWND              hwndParent;
  PSP_FILE_CALLBACK InstallMsgHandler;
  PVOID             InstallMsgHandlerContext;
  HSPFILEQ          FileQueue;
  ULONG_PTR         ClassInstallReserved;
  DWORD             Reserved;
  WCHAR             DriverPath[MAX_PATH];
} SP_DEVINSTALL_PARAMS_W, *PSP_DEVINSTALL_PARAMS_W;