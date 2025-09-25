HRESULT OPMGetVideoOutputForTarget(
  [in]  LUID                       *pAdapterLuid,
  [in]  ULONG                      VidPnTarget,
  [in]  OPM_VIDEO_OUTPUT_SEMANTICS vos,
  [out] IOPMVideoOutput            **ppOPMVideoOutput
);