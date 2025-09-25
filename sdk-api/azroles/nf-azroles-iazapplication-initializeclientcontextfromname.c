HRESULT InitializeClientContextFromName(
  [in]           BSTR             ClientName,
  [in, optional] BSTR             DomainName,
  [in, optional] VARIANT          varReserved,
  [out]          IAzClientContext **ppClientContext
);