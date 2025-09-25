typedef struct {
  DWORD    cbSize;
  HWND     hwndOwner;
  int      iShow;
  DWORD    dwFlags;
  RECT     rect;
  IUnknown *punkRel;
  OLECHAR  strNewFile[MAX_PATH];
} FVSHOWINFO, *LPFVSHOWINFO;