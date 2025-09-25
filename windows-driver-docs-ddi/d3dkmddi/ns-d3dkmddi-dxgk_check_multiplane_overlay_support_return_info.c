typedef struct DXGK_CHECK_MULTIPLANE_OVERLAY_SUPPORT_RETURN_INFO {
  union {
    struct {
      UINT FailingPlane : 4;
      UINT TryAgain : 1;
      UINT Reserved : 27;
    };
    UINT Value;
  };
} DXGK_CHECK_MULTIPLANE_OVERLAY_SUPPORT_RETURN_INFO;