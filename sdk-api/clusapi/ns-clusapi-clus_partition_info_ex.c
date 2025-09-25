typedef struct CLUS_PARTITION_INFO_EX {
  DWORD          dwFlags;
  WCHAR          szDeviceName[MAX_PATH];
  WCHAR          szVolumeLabel[MAX_PATH];
  DWORD          dwSerialNumber;
  DWORD          rgdwMaximumComponentLength;
  DWORD          dwFileSystemFlags;
  WCHAR          szFileSystem[32];
  ULARGE_INTEGER TotalSizeInBytes;
  ULARGE_INTEGER FreeSizeInBytes;
  DWORD          DeviceNumber;
  DWORD          PartitionNumber;
  GUID           VolumeGuid;
} CLUS_PARTITION_INFO_EX, *PCLUS_PARTITION_INFO_EX;