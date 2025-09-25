WINSETUPAPI BOOL SetupInstallFromInfSectionW(
  HWND                Owner,
  HINF                InfHandle,
  PCWSTR              SectionName,
  UINT                Flags,
  HKEY                RelativeKeyRoot,
  PCWSTR              SourceRootPath,
  UINT                CopyFlags,
  PSP_FILE_CALLBACK_W MsgHandler,
  PVOID               Context,
  HDEVINFO            DeviceInfoSet,
  PSP_DEVINFO_DATA    DeviceInfoData
);