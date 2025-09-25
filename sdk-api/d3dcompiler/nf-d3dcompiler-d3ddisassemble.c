HRESULT D3DDisassemble(
  [in]           LPCVOID  pSrcData,
  [in]           SIZE_T   SrcDataSize,
  [in]           UINT     Flags,
  [in, optional] LPCSTR   szComments,
  [out]          ID3DBlob **ppDisassembly
);