WINSETUPAPI BOOL SetupDiGetDeviceInterfacePropertyW(
  [in]            HDEVINFO                  DeviceInfoSet,
  [in]            PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
  [in]            const DEVPROPKEY          *PropertyKey,
  [out]           DEVPROPTYPE               *PropertyType,
  [out]           PBYTE                     PropertyBuffer,
  [in]            DWORD                     PropertyBufferSize,
  [out, optional] PDWORD                    RequiredSize,
  [in]            DWORD                     Flags
);