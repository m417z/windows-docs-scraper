HRESULT CreateObjectFromURL(
  [in]  LPCWSTR        pwszURL,
  [in]  DWORD          dwFlags,
  [in]  IPropertyStore *pProps,
  [out] MF_OBJECT_TYPE *pObjectType,
  [out] IUnknown       **ppObject
);