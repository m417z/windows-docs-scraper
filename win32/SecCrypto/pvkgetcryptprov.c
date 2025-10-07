HRESULT WINAPI PvkGetCryptProv(
  _In_      HWND       hwnd,
  _In_      LPCWSTR    pwszCaption,
  _In_      LPCWSTR    pwszCapiProvider,
  _In_      DWORD      dwProviderType,
  _In_      LPCWSTR    pwszPvkFile,
  _In_      LPCWSTR    pwszKeyContainerName,
  _Out_     DWORD      *pdwKeySpec,
  _Out_opt_ LPWSTR     *ppwszTmpContainer,
  _Out_     HCRYPTPROV *phCryptProv
);