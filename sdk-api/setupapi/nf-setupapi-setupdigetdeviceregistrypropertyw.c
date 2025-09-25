WINSETUPAPI BOOL SetupDiGetDeviceRegistryPropertyW(
  [in]            HDEVINFO         DeviceInfoSet,
  [in]            PSP_DEVINFO_DATA DeviceInfoData,
  [in]            DWORD            Property,
  [out, optional] PDWORD           PropertyRegDataType,
  [out, optional] PBYTE            PropertyBuffer,
  [in]            DWORD            PropertyBufferSize,
  [out, optional] PDWORD           RequiredSize
);