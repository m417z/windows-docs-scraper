HRESULT SHGetKnownFolderPath(
  [in]           REFKNOWNFOLDERID rfid,
  [in]           DWORD            dwFlags,
  [in, optional] HANDLE           hToken,
  [out]          PWSTR            *ppszPath
);