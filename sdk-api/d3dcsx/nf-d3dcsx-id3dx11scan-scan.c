HRESULT Scan(
  [in] D3DX11_SCAN_DATA_TYPE     ElementType,
  [in] D3DX11_SCAN_OPCODE        OpCode,
  [in] UINT                      ElementScanSize,
  [in] ID3D11UnorderedAccessView *pSrc,
  [in] ID3D11UnorderedAccessView *pDst
);