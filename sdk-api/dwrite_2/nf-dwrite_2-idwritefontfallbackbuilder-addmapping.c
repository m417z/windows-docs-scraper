HRESULT AddMapping(
                 DWRITE_UNICODE_RANGE const *ranges,
                 UINT32                     rangesCount,
  [in]           WCHAR const                **targetFamilyNames,
                 UINT32                     targetFamilyNamesCount,
  [in, optional] IDWriteFontCollection      *fontCollection,
  [in, optional] WCHAR const                *localeName,
  [in, optional] WCHAR const                *baseFamilyName,
                 FLOAT                      scale
);