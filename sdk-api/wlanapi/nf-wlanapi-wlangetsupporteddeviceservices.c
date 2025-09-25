DWORD WlanGetSupportedDeviceServices(
  [in]  HANDLE                         hClientHandle,
  [in]  const GUID                     *pInterfaceGuid,
  [out] PWLAN_DEVICE_SERVICE_GUID_LIST *ppDevSvcGuidList
);