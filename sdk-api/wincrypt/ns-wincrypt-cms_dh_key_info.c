typedef struct _CMS_DH_KEY_INFO {
  DWORD           dwVersion;
  ALG_ID          Algid;
  LPSTR           pszContentEncObjId;
  CRYPT_DATA_BLOB PubInfo;
  void            *pReserved;
} CMS_DH_KEY_INFO, *PCMS_DH_KEY_INFO;