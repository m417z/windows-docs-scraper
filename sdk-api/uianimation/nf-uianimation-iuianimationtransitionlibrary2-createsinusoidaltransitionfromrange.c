HRESULT CreateSinusoidalTransitionFromRange(
  [in]  UI_ANIMATION_SECONDS    duration,
  [in]  DOUBLE                  minimumValue,
  [in]  DOUBLE                  maximumValue,
  [in]  UI_ANIMATION_SECONDS    period,
  [in]  UI_ANIMATION_SLOPE      slope,
  [out] IUIAnimationTransition2 **transition
);