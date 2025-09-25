typedef struct RILCBMSGCONFIG {
  DWORD               cbSize;
  DWORD               dwParams;
  DWORD               dwGWLConfigInfoSize;
  RILCBGWLCONFIGINFO  GWLConfigInfo[50];
  DWORD               dwCDMAConfigInfoSize;
  RILCBCDMACONFIGINFO CDMAConfigInfo[50];
} RILCBMSGCONFIG, *LPRILCBMSGCONFIG;