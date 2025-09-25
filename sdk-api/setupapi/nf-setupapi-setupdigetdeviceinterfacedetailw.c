WINSETUPAPI BOOL SetupDiGetDeviceInterfaceDetailW(
  [in]            HDEVINFO                           DeviceInfoSet,
  [in]            PSP_DEVICE_INTERFACE_DATA          DeviceInterfaceData,
  [out, optional] PSP_DEVICE_INTERFACE_DETAIL_DATA_W DeviceInterfaceDetailData,
  [in]            DWORD                              DeviceInterfaceDetailDataSize,
  [out, optional] PDWORD                             RequiredSize,
  [out, optional] PSP_DEVINFO_DATA                   DeviceInfoData
);