HRESULT GetItemsChangedSink(
  [in]  ISearchNotifyInlineSite *pISearchNotifyInlineSite,
  [in]  REFIID                  riid,
  [out] void                    **ppv,
  [out] GUID                    *pGUIDCatalogResetSignature,
  [out] GUID                    *pGUIDCheckPointSignature,
  [out] DWORD                   *pdwLastCheckPointNumber
);