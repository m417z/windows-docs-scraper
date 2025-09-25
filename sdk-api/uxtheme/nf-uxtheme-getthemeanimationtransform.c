HRESULT GetThemeAnimationTransform(
  [in]  HTHEME       hTheme,
  [in]  int          iStoryboardId,
  [in]  int          iTargetId,
  [in]  DWORD        dwTransformIndex,
  [out] TA_TRANSFORM *pTransform,
  [in]  DWORD        cbSize,
  [out] DWORD        *pcbSizeOut
);