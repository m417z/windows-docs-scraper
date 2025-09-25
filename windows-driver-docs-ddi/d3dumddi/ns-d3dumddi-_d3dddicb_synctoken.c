typedef struct _D3DDDICB_SYNCTOKEN {
  HANDLE       hSyncToken;
  UINT         BroadcastContextCount;
  const HANDLE *BroadcastContextArray;
} D3DDDICB_SYNCTOKEN;