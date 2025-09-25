HRESULT QuerySnapshotDeltaBitmap(
  [in]  VSS_ID idSnapshotOlder,
  [in]  VSS_ID idSnapshotYounger,
  [out] ULONG  *pcBlockSizePerBit,
  [out] ULONG  *pcBitmapLength,
  [out] BYTE   **ppbBitmap
);