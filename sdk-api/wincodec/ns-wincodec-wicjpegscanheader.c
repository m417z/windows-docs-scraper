typedef struct WICJpegScanHeader {
  UINT  cComponents;
  UINT  RestartInterval;
  DWORD ComponentSelectors;
  DWORD HuffmanTableIndices;
  BYTE  StartSpectralSelection;
  BYTE  EndSpectralSelection;
  BYTE  SuccessiveApproximationHigh;
  BYTE  SuccessiveApproximationLow;
} WICJpegScanHeader;