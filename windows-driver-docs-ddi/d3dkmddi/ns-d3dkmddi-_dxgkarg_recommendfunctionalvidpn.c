typedef struct _DXGKARG_RECOMMENDFUNCTIONALVIDPN {
  IN UINT                                 NumberOfVidPnTargets;
  IN const D3DDDI_VIDEO_PRESENT_TARGET_ID *pVidPnTargetPrioritizationVector;
  IN D3DKMDT_HVIDPN                       hRecommendedFunctionalVidPn;
  IN DXGK_RECOMMENDFUNCTIONALVIDPN_REASON RequestReason;
  IN VOID                                 *pPrivateDriverData;
  IN UINT                                 PrivateDriverDataSize;
} DXGKARG_RECOMMENDFUNCTIONALVIDPN;