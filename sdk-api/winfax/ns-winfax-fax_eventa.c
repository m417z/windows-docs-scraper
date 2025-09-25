typedef struct _FAX_EVENTA {
  DWORD    SizeOfStruct;
  FILETIME TimeStamp;
  DWORD    DeviceId;
  DWORD    EventId;
  DWORD    JobId;
} FAX_EVENTA, *PFAX_EVENTA;