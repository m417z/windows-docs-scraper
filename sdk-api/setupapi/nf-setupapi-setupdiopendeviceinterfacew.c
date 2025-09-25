WINSETUPAPI BOOL SetupDiOpenDeviceInterfaceW(
  [in]            HDEVINFO                  DeviceInfoSet,
  [in]            PCWSTR                    DevicePath,
  [in]            DWORD                     OpenFlags,
  [out, optional] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
);