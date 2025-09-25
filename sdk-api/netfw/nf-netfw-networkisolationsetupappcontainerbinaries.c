HRESULT NetworkIsolationSetupAppContainerBinaries(
  [in] PSID    applicationContainerSid,
  [in] LPCWSTR packageFullName,
  [in] LPCWSTR packageFolder,
  [in] LPCWSTR displayName,
  [in] BOOL    bBinariesFullyComputed,
  [in] LPCWSTR *binaries,
  [in] DWORD   binariesCount
);