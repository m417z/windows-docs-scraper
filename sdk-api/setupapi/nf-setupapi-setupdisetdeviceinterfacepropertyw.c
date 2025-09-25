WINSETUPAPI BOOL SetupDiSetDeviceInterfacePropertyW(
  [in]           HDEVINFO                  DeviceInfoSet,
  [in]           PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
  [in]           const DEVPROPKEY          *PropertyKey,
  [in]           DEVPROPTYPE               PropertyType,
  [in, optional] const PBYTE               PropertyBuffer,
  [in]           DWORD                     PropertyBufferSize,
  [in]           DWORD                     Flags
);