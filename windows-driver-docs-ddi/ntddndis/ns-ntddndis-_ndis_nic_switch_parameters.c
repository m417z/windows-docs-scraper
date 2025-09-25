typedef struct _NDIS_NIC_SWITCH_PARAMETERS {
  NDIS_OBJECT_HEADER           Header;
  ULONG                        Flags;
  NDIS_NIC_SWITCH_TYPE         SwitchType;
  NDIS_NIC_SWITCH_ID           SwitchId;
  NDIS_NIC_SWITCH_FRIENDLYNAME SwitchFriendlyName;
  ULONG                        NumVFs;
  ULONG                        NdisReserved1;
  ULONG                        NdisReserved2;
  ULONG                        NdisReserved3;
  ULONG                        NumQueuePairsForDefaultVPort;
} NDIS_NIC_SWITCH_PARAMETERS, *PNDIS_NIC_SWITCH_PARAMETERS;