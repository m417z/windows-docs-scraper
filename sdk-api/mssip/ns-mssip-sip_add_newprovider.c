typedef struct SIP_ADD_NEWPROVIDER_ {
  DWORD cbStruct;
  GUID  *pgSubject;
  WCHAR *pwszDLLFileName;
  WCHAR *pwszMagicNumber;
  WCHAR *pwszIsFunctionName;
  WCHAR *pwszGetFuncName;
  WCHAR *pwszPutFuncName;
  WCHAR *pwszCreateFuncName;
  WCHAR *pwszVerifyFuncName;
  WCHAR *pwszRemoveFuncName;
  WCHAR *pwszIsFunctionNameFmt2;
  PWSTR pwszGetCapFuncName;
} SIP_ADD_NEWPROVIDER, *PSIP_ADD_NEWPROVIDER;