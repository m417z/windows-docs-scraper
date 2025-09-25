HRESULT GetBaseline(
                 IDWriteFontFace        *fontFace,
                 DWRITE_BASELINE        baseline,
                 BOOL                   isVertical,
                 BOOL                   isSimulationAllowed,
                 DWRITE_SCRIPT_ANALYSIS scriptAnalysis,
  [in, optional] WCHAR const            *localeName,
  [out]          INT32                  *baselineCoordinate,
  [out]          BOOL                   *exists
);