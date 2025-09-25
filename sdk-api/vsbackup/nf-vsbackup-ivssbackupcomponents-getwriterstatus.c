HRESULT GetWriterStatus(
  [in]  UINT             iWriter,
  [out] VSS_ID           *pidInstance,
  [out] VSS_ID           *pidWriter,
  [out] BSTR             *pbstrWriter,
  [out] VSS_WRITER_STATE *pnStatus,
  [out] HRESULT          *phResultFailure
);