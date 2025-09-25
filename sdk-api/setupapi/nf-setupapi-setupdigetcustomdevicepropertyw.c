WINSETUPAPI BOOL SetupDiGetCustomDevicePropertyW(
  [in]            HDEVINFO         DeviceInfoSet,
  [in]            PSP_DEVINFO_DATA DeviceInfoData,
  [in]            PCWSTR           CustomPropertyName,
  [in]            DWORD            Flags,
  [out, optional] PDWORD           PropertyRegDataType,
  [out]           PBYTE            PropertyBuffer,
  [in]            DWORD            PropertyBufferSize,
  [out, optional] PDWORD           RequiredSize
);