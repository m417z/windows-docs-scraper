HRESULT EnqueueMakeResident(
       D3D12_RESIDENCY_FLAGS Flags,
       UINT                  NumObjects,
  [in] ID3D12Pageable        * const *ppObjects,
  [in] ID3D12Fence           *pFenceToSignal,
       UINT64                FenceValueToSignal
);