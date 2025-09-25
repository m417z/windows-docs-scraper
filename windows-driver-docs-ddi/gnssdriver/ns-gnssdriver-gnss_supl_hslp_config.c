typedef struct {
  ULONG Size;
  ULONG Version;
  CHAR  SuplHslp[MAX_SERVER_URL_NAME];
  CHAR  SuplHslpFromImsi[MAX_SERVER_URL_NAME];
  ULONG Reserved;
  BYTE  Unused[512];
} GNSS_SUPL_HSLP_CONFIG, *PGNSS_SUPL_HSLP_CONFIG;