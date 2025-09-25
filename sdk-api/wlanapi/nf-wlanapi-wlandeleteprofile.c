DWORD WlanDeleteProfile(
  [in] HANDLE     hClientHandle,
  [in] const GUID *pInterfaceGuid,
  [in] LPCWSTR    strProfileName,
       PVOID      pReserved
);