typedef struct _DXGKARG_POSTMULTIPLANEOVERLAYPRESENT {
  [in] D3DDDI_VIDEO_PRESENT_TARGET_ID VidPnTargetId;
  [in] UINT                           PhysicalAdapterMask;
  [in] DWORD                          LayerIndex;
  [in] ULONGLONG                      PresentID;
} DXGKARG_POSTMULTIPLANEOVERLAYPRESENT;