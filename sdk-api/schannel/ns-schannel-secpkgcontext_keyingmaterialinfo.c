typedef struct _SecPkgContext_KeyingMaterialInfo {
  WORD  cbLabel;
  LPSTR pszLabel;
  WORD  cbContextValue;
  PBYTE pbContextValue;
  DWORD cbKeyingMaterial;
} SecPkgContext_KeyingMaterialInfo, *PSecPkgContext_KeyingMaterialInfo;