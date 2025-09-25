typedef struct _D3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT {
  D3DKMT_HANDLE                                       hDevice;
  UINT                                                PlaneCount;
  D3DKMT_CHECK_MULTIPLANE_OVERLAY_PLANE               *pOverlayPlanes;
  BOOL                                                Supported;
  D3DKMT_CHECK_MULTIPLANE_OVERLAY_SUPPORT_RETURN_INFO ReturnInfo;
} D3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT;