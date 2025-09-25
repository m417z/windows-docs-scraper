typedef struct _SR_RESOURCE_TYPE_REPLICATED_DISK {
  SR_REPLICATED_DISK_TYPE Type;
  GUID                    ClusterDiskResourceGuid;
  GUID                    ReplicationGroupId;
  WCHAR                   ReplicationGroupName[MAX_PATH];
} SR_RESOURCE_TYPE_REPLICATED_DISK, *PSR_RESOURCE_TYPE_REPLICATED_DISK;