typedef struct tagVMRALLOCATIONINFO {
  DWORD              dwFlags;
  LPBITMAPINFOHEADER lpHdr;
  LPDDPIXELFORMAT    lpPixFmt;
  SIZE               szAspectRatio;
  DWORD              dwMinBuffers;
  DWORD              dwMaxBuffers;
  DWORD              dwInterlaceFlags;
  SIZE               szNativeSize;
} VMRALLOCATIONINFO;