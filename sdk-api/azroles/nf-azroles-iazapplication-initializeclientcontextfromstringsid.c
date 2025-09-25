HRESULT InitializeClientContextFromStringSid(
  [in]           BSTR             SidString,
  [in]           LONG             lOptions,
  [in, optional] VARIANT          varReserved,
  [out]          IAzClientContext **ppClientContext
);