DWORD WlanSetProfilePosition(
  [in] HANDLE     hClientHandle,
  [in] const GUID *pInterfaceGuid,
  [in] LPCWSTR    strProfileName,
  [in] DWORD      dwPosition,
       PVOID      pReserved
);