typedef struct {
  WCHAR    DisplayString[MAX_GOPHER_DISPLAY_TEXT + 1];
  DWORD    GopherType;
  DWORD    SizeLow;
  DWORD    SizeHigh;
  FILETIME LastModificationTime;
  WCHAR    Locator[MAX_GOPHER_LOCATOR_LENGTH + 1];
} GOPHER_FIND_DATAW, *LPGOPHER_FIND_DATAW;