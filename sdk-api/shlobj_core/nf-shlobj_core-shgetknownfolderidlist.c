HRESULT SHGetKnownFolderIDList(
  [in]  REFKNOWNFOLDERID rfid,
  [in]  DWORD            dwFlags,
  [in]  HANDLE           hToken,
  [out] PIDLIST_ABSOLUTE *ppidl
);