DWORD WlanSetProfileList(
  [in] HANDLE     hClientHandle,
  [in] const GUID *pInterfaceGuid,
  [in] DWORD      dwItems,
  [in] LPCWSTR    *strProfileNames,
       PVOID      pReserved
);