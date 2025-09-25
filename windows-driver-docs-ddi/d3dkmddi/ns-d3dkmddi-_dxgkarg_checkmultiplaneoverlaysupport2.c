typedef struct _DXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT2 {
  UINT                                              PlaneCount;
  DXGK_MULTIPLANE_OVERLAY_PLANE_WITH_SOURCE         *pPlanes;
  BOOL                                              Supported;
  DXGK_CHECK_MULTIPLANE_OVERLAY_SUPPORT_RETURN_INFO ReturnInfo;
} DXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT2;