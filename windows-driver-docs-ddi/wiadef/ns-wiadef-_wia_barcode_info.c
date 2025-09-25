typedef struct _WIA_BARCODE_INFO {
  DWORD Size;
  DWORD Type;
  DWORD Page;
  DWORD Confidence;
  DWORD XOffset;
  DWORD YOffset;
  DWORD Rotation;
  DWORD Length;
  WCHAR Text[1];
} WIA_BARCODE_INFO;