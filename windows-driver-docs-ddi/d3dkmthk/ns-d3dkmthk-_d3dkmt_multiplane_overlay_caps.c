typedef struct _D3DKMT_MULTIPLANE_OVERLAY_CAPS {
  union {
    struct {
      UINT Rotation : 1;
      UINT RotationWithoutIndependentFlip : 1;
      UINT VerticalFlip : 1;
      UINT HorizontalFlip : 1;
      UINT StretchRGB : 1;
      UINT StretchYUV : 1;
      UINT BilinearFilter : 1;
      UINT HighFilter : 1;
      UINT Shared : 1;
      UINT Immediate : 1;
      UINT Plane0ForVirtualModeOnly : 1;
      UINT Version3DDISupport : 1;
      UINT Reserved : 20;
    };
    UINT Value;
  };
} D3DKMT_MULTIPLANE_OVERLAY_CAPS;