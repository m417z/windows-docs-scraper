typedef struct _MIB_IPMCAST_SCOPE {
  DWORD             dwGroupAddress;
  DWORD             dwGroupMask;
  SCOPE_NAME_BUFFER snNameBuffer;
  DWORD             dwStatus;
} MIB_IPMCAST_SCOPE, *PMIB_IPMCAST_SCOPE;