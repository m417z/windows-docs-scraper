typedef struct _FAX_PORT_INFOW {
  DWORD   SizeOfStruct;
  DWORD   DeviceId;
  DWORD   State;
  DWORD   Flags;
  DWORD   Rings;
  DWORD   Priority;
  LPCWSTR DeviceName;
  LPCWSTR Tsid;
  LPCWSTR Csid;
} FAX_PORT_INFOW, *PFAX_PORT_INFOW;