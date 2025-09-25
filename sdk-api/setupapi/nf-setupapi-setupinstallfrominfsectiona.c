WINSETUPAPI BOOL SetupInstallFromInfSectionA(
  HWND                Owner,
  HINF                InfHandle,
  PCSTR               SectionName,
  UINT                Flags,
  HKEY                RelativeKeyRoot,
  PCSTR               SourceRootPath,
  UINT                CopyFlags,
  PSP_FILE_CALLBACK_A MsgHandler,
  PVOID               Context,
  HDEVINFO            DeviceInfoSet,
  PSP_DEVINFO_DATA    DeviceInfoData
);