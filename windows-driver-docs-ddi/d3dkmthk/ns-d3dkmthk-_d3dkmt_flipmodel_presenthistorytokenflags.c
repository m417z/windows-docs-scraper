typedef struct _D3DKMT_FLIPMODEL_PRESENTHISTORYTOKENFLAGS {
  union {
    struct {
      UINT                                    Video : 1;
      UINT                                    RestrictedContent : 1;
      UINT                                    ClipToView : 1;
      UINT                                    StereoPreferRight : 1;
      UINT                                    TemporaryMono : 1;
      UINT                                    FlipRestart : 1;
      UINT                                    HDRMetaDataChanged : 1;
      UINT                                    AlphaMode : 2;
      UINT                                    SignalLimitOnTokenCompletion : 1;
      UINT                                    YCbCrFlags : 3;
      UINT                                    IndependentFlip : 1;
      D3DKMT_FLIPMODEL_INDEPENDENT_FLIP_STAGE IndependentFlipStage : 2;
      UINT                                    IndependentFlipReleaseCount : 2;
      UINT                                    IndependentFlipForceNotifyDwm : 1;
      UINT                                    UseCustomDuration : 1;
      UINT                                    IndependentFlipRequestDwmConfirm : 1;
      UINT                                    IndependentFlipCandidate : 1;
      UINT                                    IndependentFlipCheckNeeded : 1;
      UINT                                    IndependentFlipTrueImmediate : 1;
      UINT                                    IndependentFlipRequestDwmExit : 1;
      UINT                                    CompSurfaceNotifiedEarly : 1;
      UINT                                    IndependentFlipDoNotFlip : 1;
      UINT                                    RequirePairedToken : 1;
      UINT                                    VariableRefreshOverrideEligible : 1;
      UINT                                    VailToken : 1;
#if ...
      UINT                                    Reserved : 2;
#elif
      UINT                                    Reserved : 3;
#else
      UINT                                    Reserved : 29;
#endif
    };
    UINT Value;
  };
} D3DKMT_FLIPMODEL_PRESENTHISTORYTOKENFLAGS;