HRESULT GetProperty(
  [in]          const BSTR strConfig,
  [in]          BSTR       strStorageLocation,
  [in]          BSTR       strPropertyName,
  [in]          LONG       Flags,
  [out, retval] VARIANT    *pvarProperty
);