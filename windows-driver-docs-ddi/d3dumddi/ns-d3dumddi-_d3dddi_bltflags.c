typedef struct _D3DDDI_BLTFLAGS {
  union {
    struct {
      UINT Point : 1;
      UINT Linear : 1;
      UINT SrcColorKey : 1;
      UINT DstColorKey : 1;
      UINT MirrorLeftRight : 1;
      UINT MirrorUpDown : 1;
      UINT LinearToSrgb : 1;
      UINT Rotate : 1;
      UINT BeginPresentToDwm : 1;
      UINT ContinuePresentToDwm : 1;
      UINT EndPresentToDwm : 1;
#if ...
      UINT Reserved : 21;
      UINT Discard : 1;
      UINT NoOverwrite : 1;
      UINT Tileable : 1;
#else
      UINT Reserved : 18;
#endif
    };
    UINT Value;
  };
} D3DDDI_BLTFLAGS;