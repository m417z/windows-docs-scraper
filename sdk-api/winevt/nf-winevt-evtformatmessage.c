BOOL EvtFormatMessage(
  [in]  EVT_HANDLE   PublisherMetadata,
  [in]  EVT_HANDLE   Event,
  [in]  DWORD        MessageId,
  [in]  DWORD        ValueCount,
  [in]  PEVT_VARIANT Values,
  [in]  DWORD        Flags,
  [in]  DWORD        BufferSize,
  [in]  LPWSTR       Buffer,
  [out] PDWORD       BufferUsed
);