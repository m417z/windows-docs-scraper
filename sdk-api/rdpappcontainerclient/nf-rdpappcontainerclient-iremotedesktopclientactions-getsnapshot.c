HRESULT GetSnapshot(
  [in]          SnapshotEncodingType snapshotEncoding,
  [in]          SnapshotFormatType   snapshotFormat,
  [in]          ULONG                snapshotWidth,
  [in]          ULONG                snapshotHeight,
  [out, retval] BSTR                 *snapshotData
);