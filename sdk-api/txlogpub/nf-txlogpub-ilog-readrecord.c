HRESULT ReadRecord(
  [in]      LSN   lsnToRead,
  [in, out] LSN   *plsnPrev,
  [in, out] LSN   *plsnNext,
  [out]     BYTE  **ppbData,
  [out]     ULONG *pcbData
);