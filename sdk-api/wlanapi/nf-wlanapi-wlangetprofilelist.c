DWORD WlanGetProfileList(
  [in]  HANDLE                  hClientHandle,
  [in]  const GUID              *pInterfaceGuid,
  [in]  PVOID                   pReserved,
  [out] PWLAN_PROFILE_INFO_LIST *ppProfileList
);