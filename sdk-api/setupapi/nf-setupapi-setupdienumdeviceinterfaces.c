WINSETUPAPI BOOL SetupDiEnumDeviceInterfaces(
  [in]           HDEVINFO                  DeviceInfoSet,
  [in, optional] PSP_DEVINFO_DATA          DeviceInfoData,
  [in]           const GUID                *InterfaceClassGuid,
  [in]           DWORD                     MemberIndex,
  [out]          PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
);