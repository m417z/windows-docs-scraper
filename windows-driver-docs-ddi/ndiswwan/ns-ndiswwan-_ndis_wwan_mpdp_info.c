typedef struct _NDIS_WWAN_MPDP_INFO {
  WWAN_MPDP_OPERATION   Operation;
  GUID                  ChildInterfaceGUID;
  NDIS_WWAN_MAC_ADDRESS MacAddr;
} NDIS_WWAN_MPDP_INFO, *PNDIS_WWAN_MPDP_INFO;