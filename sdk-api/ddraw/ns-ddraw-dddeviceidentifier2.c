typedef struct tagDDDEVICEIDENTIFIER2 {
  char          szDriver[MAX_DDDEVICEID_STRING];
  char          szDescription[MAX_DDDEVICEID_STRING];
  LARGE_INTEGER liDriverVersion;
  DWORD         dwDriverVersionLowPart;
  DWORD         dwDriverVersionHighPart;
  DWORD         dwVendorId;
  DWORD         dwDeviceId;
  DWORD         dwSubSysId;
  DWORD         dwRevision;
  GUID          guidDeviceIdentifier;
  DWORD         dwWHQLLevel;
} DDDEVICEIDENTIFIER2, *LPDDDEVICEIDENTIFIER2;