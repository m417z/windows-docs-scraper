HRESULT UpdateObjectWithPropertiesAndData(
  [in]      LPCWSTR               pszObjectID,
  [in]      IPortableDeviceValues *pProperties,
  [out]     IStream               **ppData,
  [in, out] DWORD                 *pdwOptimalWriteBufferSize
);