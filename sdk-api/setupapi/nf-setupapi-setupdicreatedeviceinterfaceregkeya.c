WINSETUPAPI HKEY SetupDiCreateDeviceInterfaceRegKeyA(
  [in]           HDEVINFO                  DeviceInfoSet,
  [in]           PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
                 DWORD                     Reserved,
  [in]           REGSAM                    samDesired,
  [in, optional] HINF                      InfHandle,
  [in, optional] PCSTR                     InfSectionName
);