HRESULT CreateDiscreteVectorTransition(
  [in]  UI_ANIMATION_SECONDS    delay,
  [in]  const DOUBLE            *finalValue,
  [in]  UINT                    cDimension,
  [in]  UI_ANIMATION_SECONDS    hold,
  [out] IUIAnimationTransition2 **transition
);