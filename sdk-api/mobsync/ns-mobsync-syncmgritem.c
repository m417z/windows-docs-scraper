typedef struct _tagSYNCMGRITEM {
  DWORD    cbSize;
  DWORD    dwFlags;
  GUID     ItemID;
  DWORD    dwItemState;
  HICON    hIcon;
  WCHAR    wszItemName[128];
  FILETIME ftLastUpdate;
} SYNCMGRITEM, *LPSYNCMGRITEM;