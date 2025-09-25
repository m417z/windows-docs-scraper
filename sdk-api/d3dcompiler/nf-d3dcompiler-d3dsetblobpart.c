HRESULT D3DSetBlobPart(
  [in]  LPCVOID       pSrcData,
  [in]  SIZE_T        SrcDataSize,
  [in]  D3D_BLOB_PART Part,
  [in]  UINT          Flags,
  [in]  LPCVOID       pPart,
  [in]  SIZE_T        PartSize,
  [out] ID3DBlob      **ppNewShader
);