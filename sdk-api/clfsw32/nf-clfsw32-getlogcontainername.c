CLFSUSER_API BOOL GetLogContainerName(
  [in]                HANDLE            hLog,
  [in]                CLFS_CONTAINER_ID cidLogicalContainer,
  [in, out]           LPCWSTR           pwstrContainerName,
  [in]                ULONG             cLenContainerName,
  [in, out, optional] PULONG            pcActualLenContainerName
);