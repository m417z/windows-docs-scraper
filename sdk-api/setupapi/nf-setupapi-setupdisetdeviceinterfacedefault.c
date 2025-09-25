WINSETUPAPI BOOL SetupDiSetDeviceInterfaceDefault(
  [in]      HDEVINFO                  DeviceInfoSet,
  [in, out] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
  [in]      DWORD                     Flags,
            PVOID                     Reserved
);