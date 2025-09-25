CLFSUSER_API BOOL TruncateLog(
  [in]                PVOID        pvMarshal,
  [in]                PCLFS_LSN    plsnEnd,
  [in, out, optional] LPOVERLAPPED lpOverlapped
);