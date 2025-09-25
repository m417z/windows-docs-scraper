WINSETUPAPI BOOL SetupDiOpenDeviceInterfaceA(
  [in]            HDEVINFO                  DeviceInfoSet,
  [in]            PCSTR                     DevicePath,
  [in]            DWORD                     OpenFlags,
  [out, optional] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
);