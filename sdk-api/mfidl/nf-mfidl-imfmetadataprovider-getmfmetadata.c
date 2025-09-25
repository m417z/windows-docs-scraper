HRESULT GetMFMetadata(
  [in]  IMFPresentationDescriptor *pPresentationDescriptor,
  [in]  DWORD                     dwStreamIdentifier,
  [in]  DWORD                     dwFlags,
  [out] IMFMetadata               **ppMFMetadata
);