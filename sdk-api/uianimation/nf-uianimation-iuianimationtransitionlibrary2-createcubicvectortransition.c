HRESULT CreateCubicVectorTransition(
  [in]  UI_ANIMATION_SECONDS    duration,
  [in]  const DOUBLE            *finalValue,
  [in]  const DOUBLE            *finalVelocity,
  [in]  UINT                    cDimension,
  [out] IUIAnimationTransition2 **transition
);