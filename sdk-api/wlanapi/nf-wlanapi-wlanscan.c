DWORD WlanScan(
  [in]           HANDLE               hClientHandle,
  [in]           const GUID           *pInterfaceGuid,
  [in, optional] const PDOT11_SSID    pDot11Ssid,
  [in, optional] const PWLAN_RAW_DATA pIeData,
                 PVOID                pReserved
);