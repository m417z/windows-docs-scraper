HRESULT RepeatBetweenKeyframes(
  [in] UI_ANIMATION_KEYFRAME                   startKeyframe,
  [in] UI_ANIMATION_KEYFRAME                   endKeyframe,
  [in] DOUBLE                                  cRepetition,
  [in] UI_ANIMATION_REPEAT_MODE                repeatMode,
  [in] IUIAnimationLoopIterationChangeHandler2 *pIterationChangeHandler,
  [in] UINT_PTR                                id,
  [in] BOOL                                    fRegisterForNextAnimationEvent
);