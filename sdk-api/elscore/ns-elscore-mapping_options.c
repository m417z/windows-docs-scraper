typedef struct _MAPPING_OPTIONS {
  size_t                  Size;
  LPWSTR                  pszInputLanguage;
  LPWSTR                  pszOutputLanguage;
  LPWSTR                  pszInputScript;
  LPWSTR                  pszOutputScript;
  LPWSTR                  pszInputContentType;
  LPWSTR                  pszOutputContentType;
  LPWSTR                  pszUILanguage;
  PFN_MAPPINGCALLBACKPROC pfnRecognizeCallback;
  LPVOID                  pRecognizeCallerData;
  DWORD                   dwRecognizeCallerDataSize;
  PFN_MAPPINGCALLBACKPROC pfnActionCallback;
  LPVOID                  pActionCallerData;
  DWORD                   dwActionCallerDataSize;
  DWORD                   dwServiceFlag;
  unsigned                GetActionDisplayName : 1;
} MAPPING_OPTIONS, *PMAPPING_OPTIONS;