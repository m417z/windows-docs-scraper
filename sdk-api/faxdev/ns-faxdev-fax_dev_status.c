typedef struct _FAX_DEV_STATUS {
  DWORD  SizeOfStruct;
  DWORD  StatusId;
  DWORD  StringId;
  DWORD  PageCount;
  LPWSTR CSI;
  LPWSTR CallerId;
  LPWSTR RoutingInfo;
  DWORD  ErrorCode;
  DWORD  Reserved[3];
} FAX_DEV_STATUS, *PFAX_DEV_STATUS;