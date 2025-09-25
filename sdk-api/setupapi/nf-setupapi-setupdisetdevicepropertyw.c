WINSETUPAPI BOOL SetupDiSetDevicePropertyW(
  [in]           HDEVINFO         DeviceInfoSet,
  [in]           PSP_DEVINFO_DATA DeviceInfoData,
  [in]           const DEVPROPKEY *PropertyKey,
  [in]           DEVPROPTYPE      PropertyType,
  [in, optional] const PBYTE      PropertyBuffer,
  [in]           DWORD            PropertyBufferSize,
  [in]           DWORD            Flags
);