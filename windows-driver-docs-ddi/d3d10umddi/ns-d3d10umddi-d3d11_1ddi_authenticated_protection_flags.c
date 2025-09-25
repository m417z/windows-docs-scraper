typedef struct D3D11_1DDI_AUTHENTICATED_PROTECTION_FLAGS {
  union {
    struct {
      UINT ProtectionEnabled : 1;
      UINT OverlayOrFullscreenRequired : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} D3D11_1DDI_AUTHENTICATED_PROTECTION_FLAGS;