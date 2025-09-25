typedef struct _WLAN_HOSTED_NETWORK_STATUS {
  WLAN_HOSTED_NETWORK_STATE      HostedNetworkState;
  GUID                           IPDeviceID;
  DOT11_MAC_ADDRESS              wlanHostedNetworkBSSID;
  DOT11_PHY_TYPE                 dot11PhyType;
  ULONG                          ulChannelFrequency;
  DWORD                          dwNumberOfPeers;
#if ...
  WLAN_HOSTED_NETWORK_PEER_STATE *PeerList[];
#else
  WLAN_HOSTED_NETWORK_PEER_STATE PeerList[1];
#endif
} WLAN_HOSTED_NETWORK_STATUS, *PWLAN_HOSTED_NETWORK_STATUS;