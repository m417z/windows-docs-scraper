typedef enum _FILE_STORAGE_TIER_MEDIA_TYPE {
  FileStorageTierMediaTypeUnspecified = 0,
  FileStorageTierMediaTypeDisk = 1,
  FileStorageTierMediaTypeSsd = 2,
  FileStorageTierMediaTypeScm = 4,
  FileStorageTierMediaTypeMax
} FILE_STORAGE_TIER_MEDIA_TYPE, *PFILE_STORAGE_TIER_MEDIA_TYPE;