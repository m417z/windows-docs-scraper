typedef struct {
  CHAR     DisplayString[MAX_GOPHER_DISPLAY_TEXT + 1];
  DWORD    GopherType;
  DWORD    SizeLow;
  DWORD    SizeHigh;
  FILETIME LastModificationTime;
  CHAR     Locator[MAX_GOPHER_LOCATOR_LENGTH + 1];
} GOPHER_FIND_DATAA, *LPGOPHER_FIND_DATAA;