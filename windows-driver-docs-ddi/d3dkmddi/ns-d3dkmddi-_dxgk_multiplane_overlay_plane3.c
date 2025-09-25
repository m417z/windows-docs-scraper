typedef struct _DXGK_MULTIPLANE_OVERLAY_PLANE3 {
  UINT                                LayerIndex;
  ULONGLONG                           PresentId;
  DXGK_PLANE_SPECIFIC_INPUT_FLAGS     InputFlags;
  DXGK_PLANE_SPECIFIC_OUTPUT_FLAGS    OutputFlags;
  UINT                                MaxImmediateFlipLine;
  UINT                                ContextCount;
  DXGK_PRIMARYCONTEXTDATA             **ppContextData;
  UINT                                DriverPrivateDataSize;
  PVOID                               pDriverPrivateData;
  DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES3 PlaneAttributes;
} DXGK_MULTIPLANE_OVERLAY_PLANE3;