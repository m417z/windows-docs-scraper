HRESULT GetThemeAnimationProperty(
  [in]  HTHEME      hTheme,
  [in]  int         iStoryboardId,
  [in]  int         iTargetId,
  [in]  TA_PROPERTY eProperty,
  [out] VOID        *pvProperty,
  [in]  DWORD       cbSize,
  [out] DWORD       *pcbSizeOut
);