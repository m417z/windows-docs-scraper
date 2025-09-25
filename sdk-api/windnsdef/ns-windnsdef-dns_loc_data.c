typedef struct {
  WORD  wVersion;
  WORD  wSize;
  WORD  wHorPrec;
  WORD  wVerPrec;
  DWORD dwLatitude;
  DWORD dwLongitude;
  DWORD dwAltitude;
} DNS_LOC_DATA, *PDNS_LOC_DATA;