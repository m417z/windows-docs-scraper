DXGKCB_MIRACAST_REPORT_CHUNK_INFO DxgkcbMiracastReportChunkInfo;

NTSTATUS DxgkcbMiracastReportChunkInfo(
  [in] HANDLE MiracastHandle,
  [in] DXGK_MIRACAST_CHUNK_INFO *pChunkInfo,
  [in] PVOID pPrivateDriverData,
  [in] UINT PrivateDataDriverSize
)
{...}