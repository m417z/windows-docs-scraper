HRESULT FindNextAttrTransition(
  [in]  IAnchor         *paStart,
  [in]  IAnchor         *paHalt,
  [in]  ULONG           cFilterAttrs,
  [in]  const TS_ATTRID *paFilterAttrs,
  [in]  DWORD           dwFlags,
  [out] BOOL            *pfFound,
  [out] LONG            *plFoundOffset
);