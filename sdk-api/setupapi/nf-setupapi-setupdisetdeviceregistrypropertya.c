WINSETUPAPI BOOL SetupDiSetDeviceRegistryPropertyA(
  [in]           HDEVINFO         DeviceInfoSet,
  [in, out]      PSP_DEVINFO_DATA DeviceInfoData,
  [in]           DWORD            Property,
  [in, optional] const BYTE       *PropertyBuffer,
  [in]           DWORD            PropertyBufferSize
);