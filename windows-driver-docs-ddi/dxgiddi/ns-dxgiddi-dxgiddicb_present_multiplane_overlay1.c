typedef struct DXGIDDICB_PRESENT_MULTIPLANE_OVERLAY1 {
  void                                  *pDXGIContext;
  DWORD                                 PresentPlaneCount;
  DXGIDDI_MULTIPLANE_OVERLAY_PLANE_INFO **ppPresentPlanes;
} DXGIDDICB_PRESENT_MULTIPLANE_OVERLAY1;