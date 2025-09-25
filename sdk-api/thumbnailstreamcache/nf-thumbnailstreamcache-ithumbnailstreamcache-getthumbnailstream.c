HRESULT GetThumbnailStream(
  [in]  LPCWSTR                     path,
  [in]  ULONGLONG                   cacheId,
  [in]  ThumbnailStreamCacheOptions options,
  [in]  UINT                        requestedThumbnailSize,
  [out] SIZE                        *thumbnailSize,
  [out] IStream                     **thumbnailStream
);