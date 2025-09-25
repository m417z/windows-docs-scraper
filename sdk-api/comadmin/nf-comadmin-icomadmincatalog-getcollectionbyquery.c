HRESULT GetCollectionByQuery(
  [in]          BSTR      bstrCollName,
  [in]          SAFEARRAY **ppsaVarQuery,
  [out, retval] IDispatch **ppCatalogCollection
);