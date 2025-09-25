typedef struct _CLUS_CSV_VOLUME_INFO {
  ULARGE_INTEGER                     VolumeOffset;
  DWORD                              PartitionNumber;
  CLUSTER_CSV_VOLUME_FAULT_STATE     FaultState;
  CLUSTER_SHARED_VOLUME_BACKUP_STATE BackupState;
  WCHAR                              szVolumeFriendlyName[MAX_PATH];
  WCHAR                              szVolumeName[50];
} CLUS_CSV_VOLUME_INFO, *PCLUS_CSV_VOLUME_INFO;