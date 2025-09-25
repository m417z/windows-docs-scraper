typedef struct _FAX_PORT_INFOA {
  DWORD  SizeOfStruct;
  DWORD  DeviceId;
  DWORD  State;
  DWORD  Flags;
  DWORD  Rings;
  DWORD  Priority;
  LPCSTR DeviceName;
  LPCSTR Tsid;
  LPCSTR Csid;
} FAX_PORT_INFOA, *PFAX_PORT_INFOA;