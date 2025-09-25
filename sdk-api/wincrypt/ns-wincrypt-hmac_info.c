typedef struct _HMAC_Info {
  ALG_ID HashAlgid;
  BYTE   *pbInnerString;
  DWORD  cbInnerString;
  BYTE   *pbOuterString;
  DWORD  cbOuterString;
} HMAC_INFO, *PHMAC_INFO;