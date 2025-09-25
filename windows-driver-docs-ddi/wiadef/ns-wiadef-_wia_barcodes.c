typedef struct _WIA_BARCODES {
  DWORD            Tag;
  DWORD            Version;
  DWORD            Size;
  DWORD            Count;
  WIA_BARCODE_INFO Barcodes[1];
} WIA_BARCODES;