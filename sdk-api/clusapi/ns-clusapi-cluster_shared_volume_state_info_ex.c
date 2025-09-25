typedef struct _CLUSTER_SHARED_VOLUME_STATE_INFO_EX {
  WCHAR                       szVolumeName[MAX_PATH];
  WCHAR                       szNodeName[MAX_PATH];
  CLUSTER_SHARED_VOLUME_STATE VolumeState;
  WCHAR                       szVolumeFriendlyName[MAX_PATH];
  ULONGLONG                   RedirectedIOReason;
  ULONGLONG                   VolumeRedirectedIOReason;
} CLUSTER_SHARED_VOLUME_STATE_INFO_EX, *PCLUSTER_SHARED_VOLUME_STATE_INFO_EX;