CLFSUSER_API BOOL AdvanceLogBase(
  [in, out]           PVOID        pvMarshal,
  [in]                PCLFS_LSN    plsnBase,
  [in]                ULONG        fFlags,
  [in, out, optional] LPOVERLAPPED pOverlapped
);