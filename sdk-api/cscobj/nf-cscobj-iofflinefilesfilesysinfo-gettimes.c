HRESULT GetTimes(
  [in]  OFFLINEFILES_ITEM_COPY copy,
  [out] FILETIME               *pftCreationTime,
  [out] FILETIME               *pftLastWriteTime,
  [out] FILETIME               *pftChangeTime,
  [out] FILETIME               *pftLastAccessTime
);