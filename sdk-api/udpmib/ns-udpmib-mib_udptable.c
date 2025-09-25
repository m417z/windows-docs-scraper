typedef struct _MIB_UDPTABLE {
  DWORD      dwNumEntries;
  MIB_UDPROW table[ANY_SIZE];
} MIB_UDPTABLE, *PMIB_UDPTABLE;