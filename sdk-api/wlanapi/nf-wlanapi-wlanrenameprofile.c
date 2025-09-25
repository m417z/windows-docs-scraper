DWORD WlanRenameProfile(
  [in] HANDLE     hClientHandle,
  [in] const GUID *pInterfaceGuid,
  [in] LPCWSTR    strOldProfileName,
  [in] LPCWSTR    strNewProfileName,
       PVOID      pReserved
);