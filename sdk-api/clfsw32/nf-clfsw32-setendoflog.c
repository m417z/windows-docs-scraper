CLFSUSER_API BOOL SetEndOfLog(
  [in]                HANDLE       hLog,
  [in]                PCLFS_LSN    plsnEnd,
  [in, out, optional] LPOVERLAPPED lpOverlapped
);