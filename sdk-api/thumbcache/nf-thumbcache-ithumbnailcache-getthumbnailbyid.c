HRESULT GetThumbnailByID(
  [in]            WTS_THUMBNAILID thumbnailID,
  [in]            UINT            cxyRequestedThumbSize,
  [out, optional] ISharedBitmap   **ppvThumb,
  [out, optional] WTS_CACHEFLAGS  *pOutFlags
);