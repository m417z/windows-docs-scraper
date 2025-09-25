typedef struct _FAX_EVENTW {
  DWORD    SizeOfStruct;
  FILETIME TimeStamp;
  DWORD    DeviceId;
  DWORD    EventId;
  DWORD    JobId;
} FAX_EVENTW, *PFAX_EVENTW;