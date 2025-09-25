HRESULT CreateAccelerateDecelerateTransition(
  [in]  UI_ANIMATION_SECONDS   duration,
  [in]  DOUBLE                 finalValue,
  [in]  DOUBLE                 accelerationRatio,
  [in]  DOUBLE                 decelerationRatio,
  [out] IUIAnimationTransition **transition
);