HRESULT FindNextAttrTransition(
  [in]  LONG            acpStart,
  [in]  LONG            acpHalt,
  [in]  ULONG           cFilterAttrs,
  [in]  const TS_ATTRID *paFilterAttrs,
  [in]  DWORD           dwFlags,
  [out] LONG            *pacpNext,
  [out] BOOL            *pfFound,
  [out] LONG            *plFoundOffset
);