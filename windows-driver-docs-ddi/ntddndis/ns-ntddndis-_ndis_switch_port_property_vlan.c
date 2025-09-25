typedef struct _NDIS_SWITCH_PORT_PROPERTY_VLAN {
  NDIS_OBJECT_HEADER         Header;
  ULONG                      Flags;
  NDIS_SWITCH_PORT_VLAN_MODE OperationMode;
  union {
    struct {
      UINT16 AccessVlanId;
      UINT16 NativeVlanId;
      UINT64 PruneVlanIdArray[64];
      UINT64 TrunkVlanIdArray[64];
    } VlanProperties;
    struct {
      NDIS_SWITCH_PORT_PVLAN_MODE PvlanMode;
      UINT16                      PrimaryVlanId;
      union {
        UINT16 SecondaryVlanId;
        UINT64 SecondaryVlanIdArray[64];
      };
    } PvlanProperties;
  };
} NDIS_SWITCH_PORT_PROPERTY_VLAN, *PNDIS_SWITCH_PORT_PROPERTY_VLAN;