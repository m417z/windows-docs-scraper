typedef struct _NDIS_WWAN_MAC_INFO {
  ULONG                 uReserved;
  ULONG                 uNdisPortNumber;
  NDIS_WWAN_MAC_ADDRESS MacAddr;
} NDIS_WWAN_MAC_INFO, *PNDIS_WWAN_MAC_INFO;