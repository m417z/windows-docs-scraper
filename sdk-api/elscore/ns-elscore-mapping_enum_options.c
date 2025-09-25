typedef struct _MAPPING_ENUM_OPTIONS {
  size_t   Size;
  LPWSTR   pszCategory;
  LPWSTR   pszInputLanguage;
  LPWSTR   pszOutputLanguage;
  LPWSTR   pszInputScript;
  LPWSTR   pszOutputScript;
  LPWSTR   pszInputContentType;
  LPWSTR   pszOutputContentType;
  GUID     *pGuid;
  unsigned OnlineService : 2;
  unsigned ServiceType : 2;
} MAPPING_ENUM_OPTIONS, *PMAPPING_ENUM_OPTIONS;