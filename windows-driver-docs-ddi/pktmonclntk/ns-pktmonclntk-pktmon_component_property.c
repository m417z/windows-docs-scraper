typedef struct _PKTMON_COMPONENT_PROPERTY {
  PKTMON_COMPONENT_PROPERTY_ID Id;
  union {
    ULONG              IfIndex;
    ULONG              MiniportIfIndex;
    ULONG              LowerIfIndex;
    ULONG              VmsExtIfIndex;
    ULONG              LowestIfIndex;
    ULONG              NdisMedium;
    ULONG              IpIfIndex;
    ULONG              Vsid;
    ULONG              Vlan;
    ULONG              CompartmentId;
    USHORT             OptDataPath;
    USHORT             NdisObject;
    USHORT             EtherType;
    GUID               IfGuid;
    PKTMON_MAC_ADDRESS MacAddress;
    CHAR               VMSwitchName[PKTMON_MAX_PROPERTY_LENGTH_BYTES];
    SOCKADDR_INET      SockAddr;
  };
} PKTMON_COMPONENT_PROPERTY;