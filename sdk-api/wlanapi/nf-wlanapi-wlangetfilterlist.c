DWORD WlanGetFilterList(
  [in]  HANDLE                hClientHandle,
  [in]  WLAN_FILTER_LIST_TYPE wlanFilterListType,
        PVOID                 pReserved,
  [out] PDOT11_NETWORK_LIST   *ppNetworkList
);