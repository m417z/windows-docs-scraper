WINSETUPAPI BOOL SetupDiCreateDeviceInterfaceW(
  [in]            HDEVINFO                  DeviceInfoSet,
  [in]            PSP_DEVINFO_DATA          DeviceInfoData,
  [in]            const GUID                *InterfaceClassGuid,
  [in, optional]  PCWSTR                    ReferenceString,
  [in]            DWORD                     CreationFlags,
  [out, optional] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
);