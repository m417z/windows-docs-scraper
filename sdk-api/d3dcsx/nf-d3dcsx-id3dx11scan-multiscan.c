HRESULT Multiscan(
  [in] D3DX11_SCAN_DATA_TYPE     ElementType,
  [in] D3DX11_SCAN_OPCODE        OpCode,
  [in] UINT                      ElementScanSize,
  [in] UINT                      ElementScanPitch,
  [in] UINT                      ScanCount,
  [in] ID3D11UnorderedAccessView *pSrc,
  [in] ID3D11UnorderedAccessView *pDst
);