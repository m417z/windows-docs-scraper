typedef struct {
  ULONG                      Size;
  KSDS3D_HRTF_FILTER_QUALITY Quality;
  FLOAT                      SampleRate;
  ULONG                      MaxFilterSize;
  ULONG                      FilterTransientMuteLength;
  ULONG                      FilterOverlapBufferLength;
  ULONG                      OutputOverlapBufferLength;
  ULONG                      Reserved;
} KSDS3D_HRTF_INIT_MSG, *PKSDS3D_HRTF_INIT_MSG;