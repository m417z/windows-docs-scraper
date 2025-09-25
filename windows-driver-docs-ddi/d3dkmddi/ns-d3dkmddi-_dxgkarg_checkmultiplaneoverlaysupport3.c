typedef struct _DXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT3 {
  UINT                                                 PlaneCount;
  DXGK_MULTIPLANE_OVERLAY_PLANE_WITH_SOURCE2           **ppPlanes;
  UINT                                                 PostCompositionCount;
  DXGK_MULTIPLANE_OVERLAY_POST_COMPOSITION_WITH_SOURCE **ppPostComposition;
  BOOL                                                 Supported;
  DXGK_CHECK_MULTIPLANE_OVERLAY_SUPPORT_RETURN_INFO    ReturnInfo;
} DXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT3;