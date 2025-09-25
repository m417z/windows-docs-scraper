typedef struct _WABEXTDISPLAY {
  ULONG       cbSize;
  LPWABOBJECT lpWABObject;
  LPADRBOOK   lpAdrBook;
  LPMAPIPROP  lpPropObj;
  BOOL        fReadOnly;
  BOOL        fDataChanged;
  ULONG       ulFlags;
  LPVOID      lpv;
  LPTSTR      lpsz;
} WABEXTDISPLAY, *LPWABEXTDISPLAY;