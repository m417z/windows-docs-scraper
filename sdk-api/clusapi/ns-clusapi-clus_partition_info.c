typedef struct CLUS_PARTITION_INFO {
  DWORD dwFlags;
  WCHAR szDeviceName[MAX_PATH];
  WCHAR szVolumeLabel[MAX_PATH];
  DWORD dwSerialNumber;
  DWORD rgdwMaximumComponentLength;
  DWORD dwFileSystemFlags;
  WCHAR szFileSystem[32];
} CLUS_PARTITION_INFO, *PCLUS_PARTITION_INFO;