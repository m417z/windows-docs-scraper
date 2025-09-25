typedef struct _FAX_CONFIGURATIONA {
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
  LPCSTR   ArchiveDirectory;
  LPCSTR   Reserved;
} FAX_CONFIGURATIONA, *PFAX_CONFIGURATIONA;