typedef struct {
  ULONG Size;
  ULONG Version;
  CHAR  MPC[MAX_SERVER_URL_NAME];
  CHAR  PDE[MAX_SERVER_URL_NAME];
  BYTE  ApplicationTypeIndicator_MR;
  BYTE  Unused[512];
} GNSS_V2UPL_CONFIG, *PGNSS_V2UPL_CONFIG;