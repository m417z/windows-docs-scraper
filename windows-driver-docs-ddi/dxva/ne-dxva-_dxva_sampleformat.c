typedef enum _DXVA_SampleFormat {
  DXVA_SampleFormatMask,
  DXVA_SampleUnknown,
  DXVA_SamplePreviousFrame,
  DXVA_SampleProgressiveFrame,
  DXVA_SampleFieldInterleavedEvenFirst,
  DXVA_SampleFieldInterleavedOddFirst,
  DXVA_SampleFieldSingleEven,
  DXVA_SampleFieldSingleOdd,
  DXVA_SampleSubStream
} DXVA_SampleFormat;