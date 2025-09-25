typedef struct _D3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT3 {
  D3DKMT_HANDLE                                          hAdapter;
  D3DKMT_HANDLE                                          hDevice;
  UINT                                                   PlaneCount;
  D3DKMT_CHECK_MULTIPLANE_OVERLAY_PLANE3                 **ppOverlayPlanes;
  UINT                                                   PostCompositionCount;
  D3DKMT_MULTIPLANE_OVERLAY_POST_COMPOSITION_WITH_SOURCE **ppPostComposition;
  BOOL                                                   Supported;
  D3DKMT_CHECK_MULTIPLANE_OVERLAY_SUPPORT_RETURN_INFO    ReturnInfo;
} D3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT3;