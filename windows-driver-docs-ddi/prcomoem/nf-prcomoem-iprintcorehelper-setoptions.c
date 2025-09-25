HRESULT SetOptions(
  [in, optional] IN PDEVMODE                      pDevmode,
  [in]           IN DWORD                         cbSize,
  [in]           IN BOOL                          bResolveConflicts,
  [in]           IN const PRINT_FEATURE_OPTION [] pFOPairs,
  [in]           IN DWORD                         cPairs,
  [out]          OUT PDWORD                       pcPairsWritten,
  [out]          OUT PDWORD                       pdwResult
);