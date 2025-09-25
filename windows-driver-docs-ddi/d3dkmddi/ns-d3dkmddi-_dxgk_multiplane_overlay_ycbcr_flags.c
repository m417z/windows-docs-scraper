typedef struct _DXGK_MULTIPLANE_OVERLAY_YCbCr_FLAGS {
  union {
    struct {
      UINT NominalRange : 1;
      UINT Bt709 : 1;
      UINT xvYCC : 1;
      UINT Reserved : 29;
    };
    UINT Value;
  };
} DXGK_MULTIPLANE_OVERLAY_YCbCr_FLAGS;