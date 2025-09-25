HRESULT InitializeClientContextFromToken(
  [in]           ULONGLONG        ullTokenHandle,
  [in, optional] VARIANT          varReserved,
  [out]          IAzClientContext **ppClientContext
);