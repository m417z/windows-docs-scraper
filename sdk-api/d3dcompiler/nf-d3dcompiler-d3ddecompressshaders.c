HRESULT D3DDecompressShaders(
  [in]            LPCVOID  pSrcData,
  [in]            SIZE_T   SrcDataSize,
  [in]            UINT     uNumShaders,
  [in]            UINT     uStartIndex,
  [in, optional]  UINT     *pIndices,
  [in]            UINT     uFlags,
  [out]           ID3DBlob **ppShaders,
  [out, optional] UINT     *pTotalShaders
);