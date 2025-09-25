CLFSUSER_API BOOL SetLogArchiveTail(
  [in]                HANDLE    hLog,
  [in]                PCLFS_LSN plsnArchiveTail,
  [in, out, optional] LPVOID    pReserved
);