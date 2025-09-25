HRESULT GetOption(
  [in, optional] const DEVMODE *pDevmode,
  [in]           DWORD         cbSize,
  [in]           PCSTR         pszFeatureRequested,
  [out]          PCSTR         *ppszOption
);