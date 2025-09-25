DWORD WlanGetAvailableNetworkList(
  [in]  HANDLE                       hClientHandle,
  [in]  const GUID                   *pInterfaceGuid,
  [in]  DWORD                        dwFlags,
        PVOID                        pReserved,
  [out] PWLAN_AVAILABLE_NETWORK_LIST *ppAvailableNetworkList
);