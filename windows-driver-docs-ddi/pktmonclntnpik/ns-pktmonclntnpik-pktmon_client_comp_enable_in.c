typedef struct _PKTMON_CLIENT_COMP_ENABLE_IN {
  PKTMON_HEADER Header;
  HANDLE        CompContext;
  BOOLEAN       FlowEnabled;
  BOOLEAN       DropEnabled;
} PKTMON_CLIENT_COMP_ENABLE_IN;