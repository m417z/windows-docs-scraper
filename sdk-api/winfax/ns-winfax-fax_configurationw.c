typedef struct _FAX_CONFIGURATIONW {
  DWORD    SizeOfStruct;
  DWORD    Retries;
  DWORD    RetryDelay;
  DWORD    DirtyDays;
  BOOL     Branding;
  BOOL     UseDeviceTsid;
  BOOL     ServerCp;
  BOOL     PauseServerQueue;
  FAX_TIME StartCheapTime;
  FAX_TIME StopCheapTime;
  BOOL     ArchiveOutgoingFaxes;
  LPCWSTR  ArchiveDirectory;
  LPCWSTR  Reserved;
} FAX_CONFIGURATIONW, *PFAX_CONFIGURATIONW;