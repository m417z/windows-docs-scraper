HRESULT CreateVirtualChannel(
  [in]  CHAR      *szEndpointName,
  [in]  BOOL      bStatic,
  [in]  ULONG     RequestedPriority,
  [out] ULONG_PTR *phChannel
);