DWORD IPsecSaContextEnum1(
  [in]  HANDLE            engineHandle,
  [in]  HANDLE            enumHandle,
  [in]  UINT32            numEntriesRequested,
  [out] IPSEC_SA_CONTEXT1 ***entries,
  [out] UINT32            *numEntriesReturned
);