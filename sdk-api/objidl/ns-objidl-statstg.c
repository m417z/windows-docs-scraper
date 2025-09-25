typedef struct tagSTATSTG {
  LPOLESTR       pwcsName;
  DWORD          type;
  ULARGE_INTEGER cbSize;
  FILETIME       mtime;
  FILETIME       ctime;
  FILETIME       atime;
  DWORD          grfMode;
  DWORD          grfLocksSupported;
  CLSID          clsid;
  DWORD          grfStateBits;
  DWORD          reserved;
} STATSTG;