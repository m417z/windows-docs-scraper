HRESULT Process(
  [in]      BOOL             endOfInput,
  [out]     BOOL             *endOfOutput,
  [in, out] RdcBufferPointer *inputBuffer,
  [in, out] RdcNeedPointer   *outputBuffer,
  [out]     RDC_ErrorCode    *rdc_ErrorCode
);