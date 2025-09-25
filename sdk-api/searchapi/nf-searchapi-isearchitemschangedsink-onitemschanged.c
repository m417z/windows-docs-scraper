HRESULT OnItemsChanged(
  [in]  DWORD                 dwNumberOfChanges,
  [in]  SEARCH_ITEM_CHANGE [] rgDataChangeEntries,
  [out] DWORD []              rgdwDocIds,
  [out] HRESULT []            rghrCompletionCodes
);