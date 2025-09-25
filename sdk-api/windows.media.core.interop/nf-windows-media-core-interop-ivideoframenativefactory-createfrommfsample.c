HRESULT CreateFromMFSample(
  [in]           IMFSample            *data,
  [in]           REFGUID              subtype,
  [in]           UINT32               width,
  [in]           UINT32               height,
  [in]           BOOL                 forceReadOnly,
  [in, optional] const MFVideoArea    *minDisplayAperture,
  [in, optional] IMFDXGIDeviceManager *device,
  [in]           REFIID               riid,
  [out]          LPVOID               *ppv
);