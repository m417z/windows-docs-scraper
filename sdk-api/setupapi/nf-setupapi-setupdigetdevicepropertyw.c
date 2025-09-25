WINSETUPAPI BOOL SetupDiGetDevicePropertyW(
  [in]            HDEVINFO         DeviceInfoSet,
  [in]            PSP_DEVINFO_DATA DeviceInfoData,
  [in]            const DEVPROPKEY *PropertyKey,
  [out]           DEVPROPTYPE      *PropertyType,
  [out, optional] PBYTE            PropertyBuffer,
  [in]            DWORD            PropertyBufferSize,
  [out, optional] PDWORD           RequiredSize,
  [in]            DWORD            Flags
);