HRESULT CreateResource(
  [in]  IPortableDeviceValues *pResourceAttributes,
  [out] IStream               **ppData,
  [out] DWORD                 *pdwOptimalWriteBufferSize,
  [out] LPWSTR                *ppszCookie
);