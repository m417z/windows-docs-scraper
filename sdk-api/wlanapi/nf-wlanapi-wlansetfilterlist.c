DWORD WlanSetFilterList(
  [in]           HANDLE                    hClientHandle,
  [in]           WLAN_FILTER_LIST_TYPE     wlanFilterListType,
  [in, optional] const PDOT11_NETWORK_LIST pNetworkList,
                 PVOID                     pReserved
);