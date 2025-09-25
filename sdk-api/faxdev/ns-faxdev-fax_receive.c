typedef struct _FAX_RECEIVE {
  DWORD  SizeOfStruct;
  LPWSTR FileName;
  LPWSTR ReceiverName;
  LPWSTR ReceiverNumber;
  DWORD  Reserved[4];
} FAX_RECEIVE, *PFAX_RECEIVE;