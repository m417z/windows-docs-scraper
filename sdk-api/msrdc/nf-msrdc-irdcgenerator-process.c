HRESULT Process(
  [in]      BOOL                  endOfInput,
  [out]     BOOL                  *endOfOutput,
  [in, out] RdcBufferPointer      *inputBuffer,
  [in]      ULONG                 depth,
  [out]     RdcBufferPointer * [] outputBuffers,
  [out]     RDC_ErrorCode         *rdc_ErrorCode
);