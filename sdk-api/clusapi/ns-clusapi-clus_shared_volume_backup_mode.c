typedef struct _CLUS_SHARED_VOLUME_BACKUP_MODE {
  CLUSTER_SHARED_VOLUME_BACKUP_STATE BackupState;
  DWORD                              DelayTimerInSecs;
  WCHAR                              VolumeName[MAX_PATH];
} CLUS_SHARED_VOLUME_BACKUP_MODE, *PCLUS_SHARED_VOLUME_BACKUP_MODE;