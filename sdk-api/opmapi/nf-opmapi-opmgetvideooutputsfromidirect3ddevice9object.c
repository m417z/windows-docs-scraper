HRESULT OPMGetVideoOutputsFromIDirect3DDevice9Object(
  [in]  IDirect3DDevice9           *pDirect3DDevice9,
  [in]  OPM_VIDEO_OUTPUT_SEMANTICS vos,
  [out] ULONG                      *pulNumVideoOutputs,
  [out] IOPMVideoOutput            ***pppOPMVideoOutputArray
);