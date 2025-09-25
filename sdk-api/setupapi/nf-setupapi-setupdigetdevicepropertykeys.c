WINSETUPAPI BOOL SetupDiGetDevicePropertyKeys(
  [in]            HDEVINFO         DeviceInfoSet,
  [in]            PSP_DEVINFO_DATA DeviceInfoData,
  [out, optional] DEVPROPKEY       *PropertyKeyArray,
  [in]            DWORD            PropertyKeyCount,
  [out, optional] PDWORD           RequiredPropertyKeyCount,
  [in]            DWORD            Flags
);