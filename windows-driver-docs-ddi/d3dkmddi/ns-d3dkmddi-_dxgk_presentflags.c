typedef struct _DXGK_PRESENTFLAGS {
  union {
    struct {
      UINT Blt : 1;
      UINT ColorFill : 1;
      UINT Flip : 1;
      UINT FlipWithNoWait : 1;
      UINT SrcColorKey : 1;
      UINT DstColorKey : 1;
      UINT LinearToSrgb : 1;
      UINT Rotate : 1;
      UINT FlipStereo : 1;
      UINT FlipStereoTemporaryMono : 1;
      UINT FlipStereoPreferRight : 1;
      UINT BltStereoUseRight : 1;
      UINT FlipWithMultiPlaneOverlay : 1;
      UINT RedirectedFlip : 1;
#if ...
      UINT Reserved : 18;
#elif
      UINT Reserved : 19;
#else
      UINT Reserved : 24;
#endif
    };
    [in] UINT Value;
  };
} DXGK_PRESENTFLAGS;