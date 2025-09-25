HRESULT MappingRecognizeText(
  [in]           PMAPPING_SERVICE_INFO pServiceInfo,
  [in]           LPCWSTR               pszText,
  [in]           DWORD                 dwLength,
  [in]           DWORD                 dwIndex,
  [in, optional] PMAPPING_OPTIONS      pOptions,
  [in, out]      PMAPPING_PROPERTY_BAG pbag
);