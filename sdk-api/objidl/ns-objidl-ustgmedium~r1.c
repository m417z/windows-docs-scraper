typedef struct tagSTGMEDIUM {
  DWORD    tymed;
  union {
    HBITMAP       hBitmap;
    HMETAFILEPICT hMetaFilePict;
    HENHMETAFILE  hEnhMetaFile;
    HGLOBAL       hGlobal;
    LPOLESTR      lpszFileName;
    IStream       *pstm;
    IStorage      *pstg;
  } DUMMYUNIONNAME;
  IUnknown *pUnkForRelease;
} uSTGMEDIUM;