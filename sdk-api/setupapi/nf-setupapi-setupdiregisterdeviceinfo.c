WINSETUPAPI BOOL SetupDiRegisterDeviceInfo(
  [in]            HDEVINFO           DeviceInfoSet,
  [in, out]       PSP_DEVINFO_DATA   DeviceInfoData,
  [in]            DWORD              Flags,
  [in, optional]  PSP_DETSIG_CMPPROC CompareProc,
  [in, optional]  PVOID              CompareContext,
  [out, optional] PSP_DEVINFO_DATA   DupDeviceInfoData
);