WINSETUPAPI BOOL SetupDiLoadDeviceIcon(
  [in]  HDEVINFO         DeviceInfoSet,
  [in]  PSP_DEVINFO_DATA DeviceInfoData,
  [in]  UINT             cxIcon,
  [in]  UINT             cyIcon,
  [in]  DWORD            Flags,
  [out] HICON            *hIcon
);