HRESULT InvokeFunction(
  [in]      DWORD      FunctionId,
  [in]      DWORD      InputBufferByteCount,
  [in]      const BYTE *InputBuffer,
  [in, out] DWORD      *OutputBufferByteCount,
  [out]     BYTE       *OutputBuffer
);