typedef union {
  struct {
    UINT MonitorConnected : 1;
    UINT ReducedModeListDueToBandwidth : 1;
    UINT Reserved : 30;
  };
  UINT   Value;
} MIRACAST_SESSION_INFO;