HRESULT GetStackBackTrace(
  [in]      ULONG       maxFramesToCapture,
  [in, out] UINT_PTR [] stackBackTrace,
  [out]     ULONG       *framesCaptured
);