DWORD IPsecSaContextEnum0(
  [in]  HANDLE            engineHandle,
  [in]  HANDLE            enumHandle,
  [in]  UINT32            numEntriesRequested,
  [out] IPSEC_SA_CONTEXT0 ***entries,
  [out] UINT32            *numEntriesReturned
);