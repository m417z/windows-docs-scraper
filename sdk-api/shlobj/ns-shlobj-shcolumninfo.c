typedef struct {
  SHCOLUMNID scid;
  VARTYPE    vt;
  DWORD      fmt;
  UINT       cChars;
  DWORD      csFlags;
  WCHAR      wszTitle[MAX_COLUMN_NAME_LEN];
  WCHAR      wszDescription[MAX_COLUMN_DESC_LEN];
} SHCOLUMNINFO, *LPSHCOLUMNINFO;