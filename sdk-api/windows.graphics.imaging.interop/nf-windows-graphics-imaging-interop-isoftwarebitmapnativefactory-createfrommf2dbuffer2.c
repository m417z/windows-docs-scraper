HRESULT CreateFromMF2DBuffer2(
  [in]           IMF2DBuffer2      *data,
  [in]           REFGUID           subtype,
  [in]           UINT32            width,
  [in]           UINT32            height,
  [in]           BOOL              forceReadOnly,
  [in, optional] const MFVideoArea *minDisplayAperture,
  [in]           REFIID            riid,
  [out]          LPVOID            *ppv
);