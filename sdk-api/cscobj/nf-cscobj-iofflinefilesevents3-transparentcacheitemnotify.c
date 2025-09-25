HRESULT TransparentCacheItemNotify(
  [in] LPCWSTR                pszPath,
  [in] OFFLINEFILES_EVENTS    EventType,
  [in] OFFLINEFILES_ITEM_TYPE ItemType,
  [in] BOOL                   bModifiedData,
  [in] BOOL                   bModifiedAttributes,
  [in] LPCWSTR                pzsOldPath
);