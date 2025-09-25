CLFSUSER_API NTSTATUS ClfsGetContainerName(
  [in]            PLOG_FILE_OBJECT  plfoLog,
  [in]            CLFS_CONTAINER_ID cidLogicalContainer,
  [out]           PUNICODE_STRING   puszContainerName,
  [out, optional] PULONG            pcActualLenContainerName
);