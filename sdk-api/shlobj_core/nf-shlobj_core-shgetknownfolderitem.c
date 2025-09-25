HRESULT SHGetKnownFolderItem(
  [in]  REFKNOWNFOLDERID  rfid,
  [in]  KNOWN_FOLDER_FLAG flags,
  [in]  HANDLE            hToken,
  [in]  REFIID            riid,
  [out] void              **ppv
);