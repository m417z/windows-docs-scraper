HRESULT GetThumbnail(
  [in]            IShellItem      *pShellItem,
  [in]            UINT            cxyRequestedThumbSize,
  [in]            WTS_FLAGS       flags,
  [out, optional] ISharedBitmap   **ppvThumb,
  [out, optional] WTS_CACHEFLAGS  *pOutFlags,
  [out, optional] WTS_THUMBNAILID *pThumbnailID
);