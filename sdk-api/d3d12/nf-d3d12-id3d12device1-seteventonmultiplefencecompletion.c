HRESULT SetEventOnMultipleFenceCompletion(
  [in] ID3D12Fence                     * const *ppFences,
  [in] const UINT64                    *pFenceValues,
       UINT                            NumFences,
       D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags,
       HANDLE                          hEvent
);