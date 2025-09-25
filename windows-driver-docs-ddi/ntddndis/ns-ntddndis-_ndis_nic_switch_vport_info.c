typedef struct _NDIS_NIC_SWITCH_VPORT_INFO {
  NDIS_OBJECT_HEADER                         Header;
  NDIS_NIC_SWITCH_VPORT_ID                   VPortId;
  ULONG                                      Flags;
  NDIS_NIC_SWITCH_ID                         SwitchId;
  NDIS_VPORT_NAME                            VPortName;
  NDIS_SRIOV_FUNCTION_ID                     AttachedFunctionId;
  ULONG                                      NumQueuePairs;
  NDIS_NIC_SWITCH_VPORT_INTERRUPT_MODERATION InterruptModeration;
  NDIS_NIC_SWITCH_VPORT_STATE                VPortState;
  GROUP_AFFINITY                             ProcessorAffinity;
  ULONG                                      LookaheadSize;
  ULONG                                      NumFilters;
} NDIS_NIC_SWITCH_VPORT_INFO, *PNDIS_NIC_SWITCH_VPORT_INFO;