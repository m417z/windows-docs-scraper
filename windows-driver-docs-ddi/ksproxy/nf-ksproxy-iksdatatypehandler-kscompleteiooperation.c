HRESULT KsCompleteIoOperation(
  [in, out] IMediaSample  *Sample,
  [in, out] PVOID         StreamHeader,
  [in]      KSIOOPERATION IoOperation,
  [in]      BOOL          Cancelled
);