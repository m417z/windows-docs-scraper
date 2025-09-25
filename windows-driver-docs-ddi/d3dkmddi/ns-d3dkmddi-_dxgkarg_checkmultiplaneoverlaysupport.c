typedef struct _DXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT {
  UINT                                              PlaneCount;
  DXGK_CHECK_MULTIPLANE_OVERLAY_SUPPORT_PLANE       *pPlanes;
  BOOL                                              Supported;
  DXGK_CHECK_MULTIPLANE_OVERLAY_SUPPORT_RETURN_INFO ReturnInfo;
} DXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT;