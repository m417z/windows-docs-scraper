HRESULT EnumConstrainedOptions(
  [in, optional] IN const DEVMODE *pDevmode,
  [in]           IN DWORD         cbSize,
  [in]           IN PCSTR         pszFeatureKeyword,
  [out]          OUT PCSTR * []   pConstrainedOptionList,
  [out]          OUT DWORD        *pdwNumOptions
);