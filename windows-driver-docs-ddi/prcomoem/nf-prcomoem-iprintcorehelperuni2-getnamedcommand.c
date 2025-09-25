HRESULT GetNamedCommand(
  [in]  PDEVMODE pDevmode,
  [in]  DWORD    cbSize,
  [in]  PCWSTR   pszCommandName,
  [out] PBYTE    *ppCommandBytes,
  [out] DWORD    *pcbCommandSize
);