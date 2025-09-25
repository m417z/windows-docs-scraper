DWORD WlanSetProfileEapUserData(
  [in] HANDLE          hClientHandle,
  [in] const GUID      *pInterfaceGuid,
  [in] LPCWSTR         strProfileName,
  [in] EAP_METHOD_TYPE eapType,
  [in] DWORD           dwFlags,
  [in] DWORD           dwEapUserDataSize,
  [in] const LPBYTE    pbEapUserData,
       PVOID           pReserved
);