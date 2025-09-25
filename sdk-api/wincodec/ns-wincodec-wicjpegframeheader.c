typedef struct WICJpegFrameHeader {
  UINT                  Width;
  UINT                  Height;
  WICJpegTransferMatrix TransferMatrix;
  WICJpegScanType       ScanType;
  UINT                  cComponents;
  DWORD                 ComponentIdentifiers;
  DWORD                 SampleFactors;
  DWORD                 QuantizationTableIndices;
} WICJpegFrameHeader;