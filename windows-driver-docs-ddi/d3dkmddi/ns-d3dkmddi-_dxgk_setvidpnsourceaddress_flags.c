typedef struct _DXGK_SETVIDPNSOURCEADDRESS_FLAGS {
  union {
    struct {
      UINT ModeChange : 1;
      UINT FlipImmediate : 1;
      UINT FlipOnNextVSync : 1;
      UINT FlipStereo : 1;
      UINT FlipStereoTemporaryMono : 1;
      UINT FlipStereoPreferRight : 1;
      UINT SharedPrimaryTransition : 1;
      UINT IndependentFlipExclusive : 1;
      UINT MoveFlip : 1;
#if ...
      UINT Reserved : 23;
#elif
      UINT Reserved : 24;
#elif
      UINT Reserved : 25;
#else
      UINT Reserved : 29;
#endif
    };
         UINT Value;
  };
} DXGK_SETVIDPNSOURCEADDRESS_FLAGS;