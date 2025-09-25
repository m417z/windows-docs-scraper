typedef struct _MFT_REGISTRATION_INFO {
  CLSID                  clsid;
  GUID                   guidCategory;
  UINT32                 uiFlags;
  LPCWSTR                pszName;
  DWORD                  cInTypes;
  MFT_REGISTER_TYPE_INFO *pInTypes;
  DWORD                  cOutTypes;
  MFT_REGISTER_TYPE_INFO *pOutTypes;
} MFT_REGISTRATION_INFO;