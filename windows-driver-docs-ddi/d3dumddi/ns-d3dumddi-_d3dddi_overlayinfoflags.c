typedef struct _D3DDDI_OVERLAYINFOFLAGS {
  union {
    struct {
      UINT DstColorKey : 1;
      UINT DstColorKeyRange : 1;
      UINT SrcColorKey : 1;
      UINT SrcColorKeyRange : 1;
      UINT Bob : 1;
      UINT Interleaved : 1;
      UINT MirrorLeftRight : 1;
      UINT MirrorUpDown : 1;
      UINT Deinterlace : 1;
      UINT LimitedRGB : 1;
      UINT YCbCrBT709 : 1;
      UINT YCbCrxvYCC : 1;
      UINT Reserved : 20;
    };
    UINT Value;
  };
} D3DDDI_OVERLAYINFOFLAGS;