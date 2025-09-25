typedef struct __MIDL___MIDL_itf_ads_0000_0000_0012 {
  LPWSTR          ServerName;
  DWORD           ReplicaType;
  DWORD           ReplicaNumber;
  DWORD           Count;
  PADS_NETADDRESS ReplicaAddressHints;
} ADS_REPLICAPOINTER, *PADS_REPLICAPOINTER;