typedef struct {
  DWORD dwSize;
  DWORD fccType;
  DWORD fccHandler;
  DWORD dwFlags;
  DWORD dwVersion;
  DWORD dwVersionICM;
  WCHAR szName[16];
  WCHAR szDescription[128];
  WCHAR szDriver[128];
} ICINFO;