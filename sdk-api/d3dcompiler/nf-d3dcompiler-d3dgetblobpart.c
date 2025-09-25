HRESULT D3DGetBlobPart(
  [in]  LPCVOID       pSrcData,
  [in]  SIZE_T        SrcDataSize,
  [in]  D3D_BLOB_PART Part,
  [in]  UINT          Flags,
  [out] ID3DBlob      **ppPart
);