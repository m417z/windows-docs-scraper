typedef struct _NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES {
  NDIS_OBJECT_HEADER                Header;
  PNDIS_HD_SPLIT_ATTRIBUTES         HDSplitAttributes;
  PNDIS_RECEIVE_FILTER_CAPABILITIES HardwareReceiveFilterCapabilities;
  PNDIS_RECEIVE_FILTER_CAPABILITIES CurrentReceiveFilterCapabilities;
  PNDIS_NIC_SWITCH_CAPABILITIES     HardwareNicSwitchCapabilities;
  PNDIS_NIC_SWITCH_CAPABILITIES     CurrentNicSwitchCapabilities;
  PNDIS_SRIOV_CAPABILITIES          HardwareSriovCapabilities;
  PNDIS_SRIOV_CAPABILITIES          CurrentSriovCapabilities;
  PNDIS_QOS_CAPABILITIES            HardwareQosCapabilities;
  PNDIS_QOS_CAPABILITIES            CurrentQosCapabilities;
  PNDIS_GFT_OFFLOAD_CAPABILITIES    HardwareGftOffloadCapabilities;
  PNDIS_GFT_OFFLOAD_CAPABILITIES    CurrentGftOffloadCapabilities;
} NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES, *PNDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES;