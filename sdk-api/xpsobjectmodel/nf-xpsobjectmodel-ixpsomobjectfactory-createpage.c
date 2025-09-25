HRESULT CreatePage(
  [in]          const XPS_SIZE *pageDimensions,
  [in]          LPCWSTR        language,
  [in]          IOpcPartUri    *partUri,
  [out, retval] IXpsOMPage     **page
);