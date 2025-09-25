typedef struct _CLS_SCAN_CONTEXT {
  CLFS_NODE_ID               cidNode;
  PLOG_FILE_OBJECT           plfoLog;
  ULONG                      cIndex;
  ULONG                      cContainers;
  ULONG                      cContainersReturned;
  CLFS_SCAN_MODE             eScanMode;
  PCLS_CONTAINER_INFORMATION pinfoContainer;
} CLS_SCAN_CONTEXT, *PCLS_SCAN_CONTEXT, PPCLS_SCAN_CONTEXT;