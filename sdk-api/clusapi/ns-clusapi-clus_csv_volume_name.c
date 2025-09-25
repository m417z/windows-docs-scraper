typedef struct _CLUS_CSV_VOLUME_NAME {
  LARGE_INTEGER VolumeOffset;
  WCHAR         szVolumeName[MAX_PATH];
  WCHAR         szRootPath[MAX_PATH + 3];
} CLUS_CSV_VOLUME_NAME, *PCLUS_CSV_VOLUME_NAME;