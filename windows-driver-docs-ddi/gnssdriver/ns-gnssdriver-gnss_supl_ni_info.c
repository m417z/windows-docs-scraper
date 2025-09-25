typedef struct {
  ULONG Size;
  ULONG Version;
  WCHAR RequestorId[MAX_PATH];
  WCHAR ClientName[MAX_PATH];
  CHAR  SuplNiUrl[MAX_SERVER_URL_NAME];
} GNSS_SUPL_NI_INFO, *PGNSS_SUPL_NI_INFO;