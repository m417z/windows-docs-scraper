typedef struct _RTM_NEXTHOP_LIST {
  USHORT             NumNextHops;
  RTM_NEXTHOP_HANDLE NextHops[1];
} RTM_NEXTHOP_LIST, *PRTM_NEXTHOP_LIST;