typedef struct _CMS_KEY_INFO {
  DWORD  dwVersion;
  ALG_ID Algid;
  BYTE   *pbOID;
  DWORD  cbOID;
} CMS_KEY_INFO, *PCMS_KEY_INFO;