typedef struct _NDIS_KDNET_REMOVE_PF {
  NDIS_OBJECT_HEADER Header;
  NDIS_KDNET_BDF     Bdf;
  ULONG              FunctionNumber;
} NDIS_KDNET_REMOVE_PF, *PNDIS_KDNET_REMOVE_PF;