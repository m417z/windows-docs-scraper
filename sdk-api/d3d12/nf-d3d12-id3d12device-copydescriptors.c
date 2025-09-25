void CopyDescriptors(
  [in]           UINT                              NumDestDescriptorRanges,
  [in]           const D3D12_CPU_DESCRIPTOR_HANDLE *pDestDescriptorRangeStarts,
  [in, optional] const UINT                        *pDestDescriptorRangeSizes,
  [in]           UINT                              NumSrcDescriptorRanges,
  [in]           const D3D12_CPU_DESCRIPTOR_HANDLE *pSrcDescriptorRangeStarts,
  [in, optional] const UINT                        *pSrcDescriptorRangeSizes,
  [in]           D3D12_DESCRIPTOR_HEAP_TYPE        DescriptorHeapsType
);