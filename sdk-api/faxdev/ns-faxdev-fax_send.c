typedef struct _FAX_SEND {
  DWORD  SizeOfStruct;
  LPWSTR FileName;
  LPWSTR CallerName;
  LPWSTR CallerNumber;
  LPWSTR ReceiverName;
  LPWSTR ReceiverNumber;
  BOOL   Branding;
  HCALL  CallHandle;
  DWORD  Reserved[3];
} FAX_SEND, *PFAX_SEND;