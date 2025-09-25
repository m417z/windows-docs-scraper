typedef struct MS_ADDINFO_BLOB_ {
  DWORD cbStruct;
  DWORD cbMemObject;
  BYTE  *pbMemObject;
  DWORD cbMemSignedMsg;
  BYTE  *pbMemSignedMsg;
} MS_ADDINFO_BLOB, *PMS_ADDINFO_BLOB;