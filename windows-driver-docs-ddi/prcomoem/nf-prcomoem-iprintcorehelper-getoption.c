HRESULT GetOption(
  [in]  const DEVMODE *pDevmode,
  [in]  DWORD         cbSize,
  [in]  PCSTR         pszFeatureRequested,
  [out] PCSTR         *ppszOption
);