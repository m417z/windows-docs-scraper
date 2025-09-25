typedef struct CompositionFrameDisplayInstance {
  LUID                         displayAdapterLUID;
  UINT                         displayVidPnSourceId;
  UINT                         displayUniqueId;
  LUID                         renderAdapterLUID;
  CompositionFrameInstanceKind instanceKind;
  PresentationTransform        finalTransform;
  boolean                      requiredCrossAdapterCopy;
  DXGI_COLOR_SPACE_TYPE        colorSpace;
} CompositionFrameDisplayInstance;