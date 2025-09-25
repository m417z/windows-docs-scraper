typedef struct _CLS_CONTAINER_INFORMATION {
  ULONG                FileAttributes;
  ULONGLONG            CreationTime;
  ULONGLONG            LastAccessTime;
  ULONGLONG            LastWriteTime;
  LONGLONG             ContainerSize;
  ULONG                FileNameActualLength;
  ULONG                FileNameLength;
  WCHAR                FileName[CLFS_MAX_CONTAINER_INFO];
  CLFS_CONTAINER_STATE State;
  CLFS_CONTAINER_ID    PhysicalContainerId;
  CLFS_CONTAINER_ID    LogicalContainerId;
} CLS_CONTAINER_INFORMATION, *PCLS_CONTAINER_INFORMATION, PPCLS_CONTAINER_INFORMATION;