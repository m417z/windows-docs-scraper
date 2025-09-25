HRESULT GetThemePartSize(
  [in]  HTHEME    hTheme,
  [in]  HDC       hdc,
  [in]  int       iPartId,
  [in]  int       iStateId,
  [in]  LPCRECT   prc,
  [in]  THEMESIZE eSize,
  [out] SIZE      *psz
);