typedef struct _CRYPT_PROVIDER_REGDEFUSAGE {
  DWORD cbStruct;
  GUID  *pgActionID;
  WCHAR *pwszDllName;
  char  *pwszLoadCallbackDataFunctionName;
  char  *pwszFreeCallbackDataFunctionName;
} CRYPT_PROVIDER_REGDEFUSAGE, *PCRYPT_PROVIDER_REGDEFUSAGE;