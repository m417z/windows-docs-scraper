HRESULT DrtStartSearch(
  [in]           HDRT                  hDrt,
  [in]           DRT_DATA              *pKey,
  [in, optional] const DRT_SEARCH_INFO *pInfo,
                 ULONG                 timeout,
  [in]           HANDLE                hEvent,
  [in, optional] const PVOID           pvContext,
  [out]          HDRT_SEARCH_CONTEXT   *hSearchContext
);