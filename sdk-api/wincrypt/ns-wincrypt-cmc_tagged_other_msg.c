typedef struct _CMC_TAGGED_OTHER_MSG {
  DWORD            dwBodyPartID;
  LPSTR            pszObjId;
  CRYPT_OBJID_BLOB Value;
} CMC_TAGGED_OTHER_MSG, *PCMC_TAGGED_OTHER_MSG;