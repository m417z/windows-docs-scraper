WINSETUPAPI BOOL SetupDiGetDeviceInterfaceAlias(
  [in]  HDEVINFO                  DeviceInfoSet,
  [in]  PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
  [in]  const GUID                *AliasInterfaceClassGuid,
  [out] PSP_DEVICE_INTERFACE_DATA AliasDeviceInterfaceData
);