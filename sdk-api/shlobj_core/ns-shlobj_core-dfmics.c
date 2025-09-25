typedef struct {
  DWORD                 cbSize;
  DWORD                 fMask;
  LPARAM                lParam;
  UINT                  idCmdFirst;
  UINT                  idDefMax;
  LPCMINVOKECOMMANDINFO pici;
  IUnknown              *punkSite;
} DFMICS, *PDFMICS;