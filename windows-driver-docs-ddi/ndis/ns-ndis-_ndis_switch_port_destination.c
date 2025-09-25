typedef struct _NDIS_SWITCH_PORT_DESTINATION {
  NDIS_SWITCH_PORT_ID   PortId;
  NDIS_SWITCH_NIC_INDEX NicIndex;
  USHORT                IsExcluded : 1;
  USHORT                PreserveVLAN : 1;
  USHORT                PreservePriority : 1;
  USHORT                Reserved : 13;
} NDIS_SWITCH_PORT_DESTINATION, *PNDIS_SWITCH_PORT_DESTINATION;