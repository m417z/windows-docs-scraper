HRESULT GetFileFragmentLocality(
        UINT64 fileOffset,
        UINT64 fragmentSize,
  [out] BOOL   *isLocal,
        UINT64 *partialSize
);