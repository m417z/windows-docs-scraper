typedef struct tagNMOBJECTNOTIFY {
  NMHDR      hdr;
  int        iItem;
#if ...
  const IID  *piid;
#else
  const void *piid;
#endif
  void       *pObject;
  HRESULT    hResult;
  DWORD      dwFlags;
} NMOBJECTNOTIFY, *LPNMOBJECTNOTIFY;