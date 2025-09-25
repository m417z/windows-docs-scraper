HRESULT D3DDisassembleRegion(
  [in]            LPCVOID  pSrcData,
  [in]            SIZE_T   SrcDataSize,
  [in]            UINT     Flags,
  [in, optional]  LPCSTR   szComments,
  [in]            SIZE_T   StartByteOffset,
  [in]            SIZE_T   NumInsts,
  [out, optional] SIZE_T   *pFinishByteOffset,
  [out]           ID3DBlob **ppDisassembly
);