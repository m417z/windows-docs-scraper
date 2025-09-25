WINSETUPAPI BOOL SetupDiCreateDeviceInfoA(
  [in]            HDEVINFO         DeviceInfoSet,
  [in]            PCSTR            DeviceName,
  [in]            const GUID       *ClassGuid,
  [in, optional]  PCSTR            DeviceDescription,
  [in, optional]  HWND             hwndParent,
  [in]            DWORD            CreationFlags,
  [out, optional] PSP_DEVINFO_DATA DeviceInfoData
);