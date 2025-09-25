DWORD WlanSetProfileEapXmlUserData(
  [in] HANDLE     hClientHandle,
  [in] const GUID *pInterfaceGuid,
  [in] LPCWSTR    strProfileName,
  [in] DWORD      dwFlags,
  [in] LPCWSTR    strEapXmlUserData,
       PVOID      pReserved
);