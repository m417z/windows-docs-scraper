typedef union D3D11_AUTHENTICATED_PROTECTION_FLAGS {
  struct {
    UINT ProtectionEnabled : 1;
    UINT OverlayOrFullscreenRequired : 1;
    UINT Reserved : 30;
  } Flags;
  __MIDL___MIDL_itf_d3d11_0000_0034_0001 __MIDL___MIDL_itf_d3d11_0000_0034_0001;
  UINT                                   Value;
} D3D11_AUTHENTICATED_PROTECTION_FLAGS;