HRESULT RenderStream(
  [in] const GUID  *pCategory,
  [in] const GUID  *pType,
  [in] IUnknown    *pSource,
  [in] IBaseFilter *pfCompressor,
  [in] IBaseFilter *pfRenderer
);