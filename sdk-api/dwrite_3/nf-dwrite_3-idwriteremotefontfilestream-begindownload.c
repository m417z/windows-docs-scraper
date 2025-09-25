HRESULT BeginDownload(
  [in] UUID const                 *downloadOperationID,
  [in] DWRITE_FILE_FRAGMENT const *fileFragments,
       UINT32                     fragmentCount,
       IDWriteAsyncResult         **asyncResult
);