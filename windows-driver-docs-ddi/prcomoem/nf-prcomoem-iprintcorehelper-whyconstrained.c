HRESULT WhyConstrained(
  [in]  const DEVMODE              *pDevmode,
  [in]  DWORD                      cbSize,
  [in]  PCSTR                      pszFeatureKeyword,
  [in]  PCSTR                      pszOptionKeyword,
  [out] const PRINT_FEATURE_OPTION **ppFOConstraints,
  [out] DWORD                      *pdwNumOptions
);