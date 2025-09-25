HRESULT CreateCubicBezierLinearVectorTransition(
  [in]  UI_ANIMATION_SECONDS    duration,
  [in]  const DOUBLE            *finalValue,
  [in]  UINT                    cDimension,
  [in]  DOUBLE                  x1,
  [in]  DOUBLE                  y1,
  [in]  DOUBLE                  x2,
  [in]  DOUBLE                  y2,
  [out] IUIAnimationTransition2 **ppTransition
);