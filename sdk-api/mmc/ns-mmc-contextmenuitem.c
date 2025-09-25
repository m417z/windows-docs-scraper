typedef struct _CONTEXTMENUITEM {
  LPWSTR strName;
  LPWSTR strStatusBarText;
  LONG   lCommandID;
  LONG   lInsertionPointID;
  LONG   fFlags;
  LONG   fSpecialFlags;
} CONTEXTMENUITEM;