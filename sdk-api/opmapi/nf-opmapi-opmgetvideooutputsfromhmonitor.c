HRESULT OPMGetVideoOutputsFromHMONITOR(
  [in]  HMONITOR                   hMonitor,
  [in]  OPM_VIDEO_OUTPUT_SEMANTICS vos,
  [out] ULONG                      *pulNumVideoOutputs,
  [out] IOPMVideoOutput            ***pppOPMVideoOutputArray
);