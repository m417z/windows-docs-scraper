DWORD AllocateAndGetTcpExTableFromStack(
  [out] PVOID  *ppTcpTable,
  [in]  BOOL   bOrder,
  [in]  HANDLE hHeap,
  [in]  DWORD  dwFlags,
  [in]  DWORD  dwFamily
);