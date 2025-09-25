typedef struct _DXVAHDDDI_VPDEVCAPS {
  [in]  UINT        Reserved;
  [out] UINT        DeviceCaps;
  [out] UINT        FeatureCaps;
  [out] UINT        FilterCaps;
  [out] UINT        InputFormatCaps;
  [out] D3DDDI_POOL InputPool;
  [out] UINT        OutputFormatCount;
  [out] UINT        InputFormatCount;
  [out] UINT        VideoProcessorCount;
  [out] UINT        MaxInputStreams;
  [out] UINT        MaxStreamStates;
} DXVAHDDDI_VPDEVCAPS;