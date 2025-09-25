typedef struct _NDIS_NIC_SWITCH_INFO {
  NDIS_OBJECT_HEADER           Header;
  ULONG                        Flags;
  NDIS_NIC_SWITCH_TYPE         SwitchType;
  NDIS_NIC_SWITCH_ID           SwitchId;
  NDIS_NIC_SWITCH_FRIENDLYNAME SwitchFriendlyName;
  ULONG                        NumVFs;
  ULONG                        NumAllocatedVFs;
  ULONG                        NumVPorts;
  ULONG                        NumActiveVPorts;
  ULONG                        NumQueuePairsForDefaultVPort;
  ULONG                        NumQueuePairsForNonDefaultVPorts;
  ULONG                        NumActiveDefaultVPortMacAddresses;
  ULONG                        NumActiveNonDefaultVPortMacAddresses;
  ULONG                        NumActiveDefaultVPortVlanIds;
  ULONG                        NumActiveNonDefaultVPortVlanIds;
} NDIS_NIC_SWITCH_INFO, *PNDIS_NIC_SWITCH_INFO;