HRESULT ProcessOutput(
  [in]      DWORD                  dwFlags,
  [in]      DWORD                  cOutputBufferCount,
  [in, out] MFT_OUTPUT_DATA_BUFFER *pOutputSamples,
  [out]     DWORD                  *pdwStatus
);