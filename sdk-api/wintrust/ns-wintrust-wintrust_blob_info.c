typedef struct WINTRUST_BLOB_INFO_ {
  DWORD   cbStruct;
  GUID    gSubject;
  LPCWSTR pcwszDisplayName;
  DWORD   cbMemObject;
  BYTE    *pbMemObject;
  DWORD   cbMemSignedMsg;
  BYTE    *pbMemSignedMsg;
} WINTRUST_BLOB_INFO, *PWINTRUST_BLOB_INFO;