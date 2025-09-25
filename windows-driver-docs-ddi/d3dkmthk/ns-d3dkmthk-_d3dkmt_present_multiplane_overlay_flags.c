typedef struct _D3DKMT_PRESENT_MULTIPLANE_OVERLAY_FLAGS {
  union {
    struct {
      UINT FlipStereo : 1;
      UINT FlipStereoTemporaryMono : 1;
      UINT FlipStereoPreferRight : 1;
      UINT FlipDoNotWait : 1;
      UINT FlipDoNotFlip : 1;
      UINT FlipRestart : 1;
      UINT DurationValid : 1;
      UINT HDRMetaDataValid : 1;
      UINT HMD : 1;
      UINT TrueImmediate : 1;
      UINT FromDDisplay : 1;
      UINT IndirectDisplay : 1;
      UINT Reserved : 20;
    };
    UINT Value;
  };
} D3DKMT_PRESENT_MULTIPLANE_OVERLAY_FLAGS;