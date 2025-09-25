typedef struct _CRYPT_TRUST_REG_ENTRY {
  DWORD cbStruct;
  WCHAR *pwszDLLName;
  WCHAR *pwszFunctionName;
} CRYPT_TRUST_REG_ENTRY, *PCRYPT_TRUST_REG_ENTRY;