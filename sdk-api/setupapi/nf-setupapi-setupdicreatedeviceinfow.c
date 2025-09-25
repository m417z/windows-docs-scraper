WINSETUPAPI BOOL SetupDiCreateDeviceInfoW(
  [in]            HDEVINFO         DeviceInfoSet,
  [in]            PCWSTR           DeviceName,
  [in]            const GUID       *ClassGuid,
  [in, optional]  PCWSTR           DeviceDescription,
  [in, optional]  HWND             hwndParent,
  [in]            DWORD            CreationFlags,
  [out, optional] PSP_DEVINFO_DATA DeviceInfoData
);