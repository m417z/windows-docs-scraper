typedef struct _RTM_NEXTHOP_INFO {
  RTM_NET_ADDRESS   NextHopAddress;
  RTM_ENTITY_HANDLE NextHopOwner;
  ULONG             InterfaceIndex;
  USHORT            State;
  USHORT            Flags;
  PVOID             EntitySpecificInfo;
  RTM_DEST_HANDLE   RemoteNextHop;
} RTM_NEXTHOP_INFO, *PRTM_NEXTHOP_INFO;