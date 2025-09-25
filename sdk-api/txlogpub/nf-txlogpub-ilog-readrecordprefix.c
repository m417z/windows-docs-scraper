HRESULT ReadRecordPrefix(
  [in]      LSN   lsnToRead,
  [in, out] LSN   *plsnPrev,
  [in, out] LSN   *plsnNext,
  [out]     BYTE  *pbData,
  [in, out] ULONG *pcbData,
  [out]     ULONG *pcbRecord
);