typedef struct _D3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT2 {
  D3DKMT_HANDLE                                       hAdapter;
  D3DKMT_HANDLE                                       hDevice;
  UINT                                                PlaneCount;
  D3DKMT_CHECK_MULTIPLANE_OVERLAY_PLANE2              *pOverlayPlanes;
  BOOL                                                Supported;
  D3DKMT_CHECK_MULTIPLANE_OVERLAY_SUPPORT_RETURN_INFO ReturnInfo;
} D3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT2;