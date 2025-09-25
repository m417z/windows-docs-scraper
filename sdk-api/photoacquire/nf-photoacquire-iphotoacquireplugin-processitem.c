HRESULT ProcessItem(
  [in] DWORD             dwAcquireStage,
  [in] IPhotoAcquireItem *pPhotoAcquireItem,
  [in] IStream           *pOriginalItemStream,
  [in] LPCWSTR           pszFinalFilename,
  [in] IPropertyStore    *pPropertyStore
);