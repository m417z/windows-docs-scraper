typedef struct tagCONVCONTEXT {
  UINT                        cb;
  UINT                        wFlags;
  UINT                        wCountryID;
  int                         iCodePage;
  DWORD                       dwLangID;
  DWORD                       dwSecurity;
  SECURITY_QUALITY_OF_SERVICE qos;
} CONVCONTEXT, *PCONVCONTEXT;