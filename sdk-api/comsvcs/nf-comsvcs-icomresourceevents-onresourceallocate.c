HRESULT OnResourceAllocate(
  [in] COMSVCSEVENTINFO *pInfo,
  [in] ULONG64          ObjectID,
  [in] LPCOLESTR        pszType,
  [in] ULONG64          resId,
  [in] BOOL             enlisted,
  [in] DWORD            NumRated,
  [in] DWORD            Rating
);