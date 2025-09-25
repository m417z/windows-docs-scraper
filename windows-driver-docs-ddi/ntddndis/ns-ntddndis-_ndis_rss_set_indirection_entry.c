typedef struct _NDIS_RSS_SET_INDIRECTION_ENTRY {
  NDIS_NIC_SWITCH_ID       SwitchId;
  NDIS_NIC_SWITCH_VPORT_ID VPortId;
  ULONG                    Flags;
  USHORT                   IndirectionTableIndex;
  PROCESSOR_NUMBER         TargetProcessorNumber;
  NDIS_STATUS              EntryStatus;
} NDIS_RSS_SET_INDIRECTION_ENTRY, *PNDIS_RSS_SET_INDIRECTION_ENTRY;