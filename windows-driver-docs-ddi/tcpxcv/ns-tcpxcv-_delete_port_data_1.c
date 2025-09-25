typedef struct _DELETE_PORT_DATA_1 {
  WCHAR psztPortName[MAX_PORTNAME_LEN];
  BYTE  Reserved[98];
  DWORD dwVersion;
  DWORD dwReserved;
} DELETE_PORT_DATA_1, *PDELETE_PORT_DATA_1;