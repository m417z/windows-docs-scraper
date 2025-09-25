HRESULT GetModePage(
  [in]  IMAPI_MODE_PAGE_TYPE         requestedModePage,
  [in]  IMAPI_MODE_PAGE_REQUEST_TYPE requestType,
  [out] BYTE                         **modePageData,
  [out] ULONG_IMAPI2_MODE_PAGE       *byteSize
);