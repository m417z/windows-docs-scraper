typedef struct _NDIS_NIC_SWITCH_VPORT_PARAMETERS {
  NDIS_OBJECT_HEADER                         Header;
  ULONG                                      Flags;
  NDIS_NIC_SWITCH_ID                         SwitchId;
  NDIS_NIC_SWITCH_VPORT_ID                   VPortId;
  NDIS_VPORT_NAME                            VPortName;
  NDIS_SRIOV_FUNCTION_ID                     AttachedFunctionId;
  ULONG                                      NumQueuePairs;
  NDIS_NIC_SWITCH_VPORT_INTERRUPT_MODERATION InterruptModeration;
  NDIS_NIC_SWITCH_VPORT_STATE                VPortState;
  GROUP_AFFINITY                             ProcessorAffinity;
  ULONG                                      LookaheadSize;
  NDIS_NDK_PARAMETERS                        NdkParams;
  NDIS_QOS_SQ_ID                             QosSqId;
} NDIS_NIC_SWITCH_VPORT_PARAMETERS, *PNDIS_NIC_SWITCH_VPORT_PARAMETERS;