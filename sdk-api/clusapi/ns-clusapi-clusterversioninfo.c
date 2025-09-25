typedef struct CLUSTERVERSIONINFO {
  DWORD dwVersionInfoSize;
  WORD  MajorVersion;
  WORD  MinorVersion;
  WORD  BuildNumber;
  WCHAR szVendorId[64];
  WCHAR szCSDVersion[64];
  DWORD dwClusterHighestVersion;
  DWORD dwClusterLowestVersion;
  DWORD dwFlags;
  DWORD dwReserved;
} CLUSTERVERSIONINFO, *LPCLUSTERVERSIONINFO, *PCLUSTERVERSIONINFO;