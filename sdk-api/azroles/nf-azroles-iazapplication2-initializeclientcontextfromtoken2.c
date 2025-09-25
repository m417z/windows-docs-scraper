HRESULT InitializeClientContextFromToken2(
  [in]           ULONG             ulTokenHandleLowPart,
  [in]           ULONG             ulTokenHandleHighPart,
  [in, optional] VARIANT           varReserved,
  [out]          IAzClientContext2 **ppClientContext
);