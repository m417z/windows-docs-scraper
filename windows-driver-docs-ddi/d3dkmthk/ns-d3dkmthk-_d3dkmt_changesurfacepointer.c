typedef struct _D3DKMT_CHANGESURFACEPOINTER {
  HDC    hDC;
  HANDLE hBitmap;
  LPVOID pSurfacePointer;
  UINT   Width;
  UINT   Height;
  UINT   Pitch;
} D3DKMT_CHANGESURFACEPOINTER;