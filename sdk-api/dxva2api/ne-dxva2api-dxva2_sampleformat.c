typedef enum _DXVA2_SampleFormat {
  DXVA2_SampleFormatMask = 0xff,
  DXVA2_SampleUnknown = 0,
  DXVA2_SampleProgressiveFrame = 2,
  DXVA2_SampleFieldInterleavedEvenFirst = 3,
  DXVA2_SampleFieldInterleavedOddFirst = 4,
  DXVA2_SampleFieldSingleEven = 5,
  DXVA2_SampleFieldSingleOdd = 6,
  DXVA2_SampleSubStream = 7
} DXVA2_SampleFormat;