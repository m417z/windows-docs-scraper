BOOL GetDiskFreeSpaceA(
  [in]  LPCSTR  lpRootPathName,
  [out] LPDWORD lpSectorsPerCluster,
  [out] LPDWORD lpBytesPerSector,
  [out] LPDWORD lpNumberOfFreeClusters,
  [out] LPDWORD lpTotalNumberOfClusters
);