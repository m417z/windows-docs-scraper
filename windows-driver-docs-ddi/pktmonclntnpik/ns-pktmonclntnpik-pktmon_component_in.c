typedef struct _PKTMON_COMPONENT_IN {
  PKTMON_HEADER         Header;
  HANDLE                CompContext;
  PCUNICODE_STRING      Name;
  PCUNICODE_STRING      Description;
  PKTMON_COMPONENT_TYPE Type;
  PKTMON_DIRECTION      DirTagIn;
  PKTMON_DIRECTION      DirTagOut;
} PKTMON_COMPONENT_IN;