HRESULT D3DGetTraceInstructionOffsets(
  [in]            LPCVOID pSrcData,
  [in]            SIZE_T  SrcDataSize,
  [in]            UINT    Flags,
  [in]            SIZE_T  StartInstIndex,
  [in]            SIZE_T  NumInsts,
  [out, optional] SIZE_T  *pOffsets,
  [out, optional] SIZE_T  *pTotalInsts
);