typedef struct _MIB_IPMCAST_BOUNDARY {
  DWORD dwIfIndex;
  DWORD dwGroupAddress;
  DWORD dwGroupMask;
  DWORD dwStatus;
} MIB_IPMCAST_BOUNDARY, *PMIB_IPMCAST_BOUNDARY;