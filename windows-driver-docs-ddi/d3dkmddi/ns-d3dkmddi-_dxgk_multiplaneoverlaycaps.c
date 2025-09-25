typedef struct _DXGK_MULTIPLANEOVERLAYCAPS {
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
      UINT Reserved : 21;
    };
    UINT Value;
  };
} DXGK_MULTIPLANEOVERLAYCAPS;