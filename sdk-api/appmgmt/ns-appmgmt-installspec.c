typedef union _INSTALLSPEC {
  struct {
    WCHAR *Name;
    GUID  GPOId;
  } AppName;
  WCHAR  *FileExt;
  WCHAR  *ProgId;
  struct {
    GUID  Clsid;
    DWORD ClsCtx;
  } COMClass;
} INSTALLSPEC;