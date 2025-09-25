HRESULT D3DDisassemble11Trace(
  [in]  LPCVOID           pSrcData,
  [in]  SIZE_T            SrcDataSize,
  [in]  ID3D11ShaderTrace *pTrace,
  [in]  UINT              StartStep,
  [in]  UINT              NumSteps,
  [in]  UINT              Flags,
  [out] ID3D10Blob        **ppDisassembly
);