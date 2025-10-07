typedef struct _PORT_INFO_2 {
  LPTSTR pPortName;
  LPTSTR pMonitorName;
  LPTSTR pDescription;
  DWORD  fPortType;
  DWORD  Reserved;
} PORT_INFO_2, *PPORT_INFO_2;