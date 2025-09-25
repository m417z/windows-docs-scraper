typedef struct _D3DKMT_PRESENTFLAGS {
  union {
    struct {
      UINT Blt : 1;
      UINT ColorFill : 1;
      UINT Flip : 1;
      UINT FlipDoNotFlip : 1;
      UINT FlipDoNotWait : 1;
      UINT FlipRestart : 1;
      UINT DstRectValid : 1;
      UINT SrcRectValid : 1;
      UINT RestrictVidPnSource : 1;
      UINT SrcColorKey : 1;
      UINT DstColorKey : 1;
      UINT LinearToSrgb : 1;
      UINT PresentCountValid : 1;
      UINT Rotate : 1;
      UINT PresentToBitmap : 1;
      UINT RedirectedFlip : 1;
      UINT RedirectedBlt : 1;
      UINT FlipStereo : 1;
      UINT FlipStereoTemporaryMono : 1;
      UINT FlipStereoPreferRight : 1;
      UINT BltStereoUseRight : 1;
      UINT PresentHistoryTokenOnly : 1;
      UINT PresentRegionsValid : 1;
      UINT PresentDDA : 1;
      UINT ProtectedContentBlankedOut : 1;
      UINT RemoteSession : 1;
      UINT CrossAdapter : 1;
      UINT DurationValid : 1;
      UINT PresentIndirect : 1;
      UINT PresentHMD : 1;
#if ...
      UINT Reserved : 2;
#elif
      UINT Reserved : 6;
#else
      UINT Reserved : 15;
#endif
    };
         UINT Value;
  };
} D3DKMT_PRESENTFLAGS;