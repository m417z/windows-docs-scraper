typedef struct RILGBATOKEN {
  DWORD cbSize;
  DWORD cbBTIDSize;
  DWORD dwBTIDOffset;
  DWORD cbNAFKeyLifetimeSize;
  DWORD dwNAFKeyLifetimeOffset;
  DWORD cbNAFKeySize;
  DWORD dwNAFKeyOffset;
  BYTE  bData[];
} RILGBATOKEN, *LPRILGBATOKEN;