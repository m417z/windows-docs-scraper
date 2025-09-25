typedef struct _D3DKMT_PRESENT_REDIRECTED {
  [in] D3DKMT_HANDLE                   hSyncObj;
  [in] D3DKMT_HANDLE                   hDevice;
  [in] D3DKMT_ALIGN64 ULONGLONG        WaitedFenceValue;
  [in] D3DKMT_PRESENTHISTORYTOKEN      PresentHistoryToken;
       D3DKMT_PRESENT_REDIRECTED_FLAGS Flags;
  [in] D3DKMT_HANDLE                   hSource;
  [in] UINT                            PrivateDriverDataSize;
  [in] PVOID                           pPrivateDriverData;
} D3DKMT_PRESENT_REDIRECTED;