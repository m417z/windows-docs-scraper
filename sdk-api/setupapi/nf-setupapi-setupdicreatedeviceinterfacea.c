WINSETUPAPI BOOL SetupDiCreateDeviceInterfaceA(
  [in]            HDEVINFO                  DeviceInfoSet,
  [in]            PSP_DEVINFO_DATA          DeviceInfoData,
  [in]            const GUID                *InterfaceClassGuid,
  [in, optional]  PCSTR                     ReferenceString,
  [in]            DWORD                     CreationFlags,
  [out, optional] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
);