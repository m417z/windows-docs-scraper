typedef struct CLUSTERVERSIONINFO_NT4 {
  DWORD dwVersionInfoSize;
  WORD  MajorVersion;
  WORD  MinorVersion;
  WORD  BuildNumber;
  WCHAR szVendorId[64];
  WCHAR szCSDVersion[64];
} CLUSTERVERSIONINFO_NT4, *PCLUSTERVERSIONINFO_NT4;