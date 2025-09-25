typedef struct D3DKMT_CHECK_MULTIPLANE_OVERLAY_SUPPORT_RETURN_INFO {
  union {
    struct {
      UINT FailingPlane : 4;
      UINT TryAgain : 1;
      UINT Reserved : 27;
    };
    UINT Value;
  };
} D3DKMT_CHECK_MULTIPLANE_OVERLAY_SUPPORT_RETURN_INFO;