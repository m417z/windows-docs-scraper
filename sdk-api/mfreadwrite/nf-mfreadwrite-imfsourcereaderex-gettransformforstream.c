HRESULT GetTransformForStream(
  [in]  DWORD        dwStreamIndex,
  [in]  DWORD        dwTransformIndex,
  [out] GUID         *pGuidCategory,
  [out] IMFTransform **ppTransform
);