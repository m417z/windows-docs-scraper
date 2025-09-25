typedef struct _PORT_DATA_LIST_1 {
  DWORD       dwVersion;
  DWORD       cPortData;
  PORT_DATA_2 pPortData[1];
} PORT_DATA_LIST_1, *PPORT_DATA_LIST_1;