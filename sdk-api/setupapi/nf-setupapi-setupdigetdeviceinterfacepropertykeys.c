WINSETUPAPI BOOL SetupDiGetDeviceInterfacePropertyKeys(
  [in]            HDEVINFO                  DeviceInfoSet,
  [in]            PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
  [out, optional] DEVPROPKEY                *PropertyKeyArray,
  [in]            DWORD                     PropertyKeyCount,
  [out, optional] PDWORD                    RequiredPropertyKeyCount,
  [in]            DWORD                     Flags
);