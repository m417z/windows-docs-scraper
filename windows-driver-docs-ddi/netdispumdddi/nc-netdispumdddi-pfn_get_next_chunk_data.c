PFN_GET_NEXT_CHUNK_DATA PfnGetNextChunkData;

NTSTATUS PfnGetNextChunkData(
  [in]           HANDLE hMiracastDeviceHandle,
  [in]           UINT TimeoutInMilliseconds,
  [in]           UINT AdditionalWaitEventCount,
  [in, optional] HANDLE *pAdditionalWaitEvents,
  [in, out]      UINT *pChunkDataBufferSize,
  [out]          MIRACAST_CHUNK_DATA *pChunkDataBuffer,
  [out]          UINT *pOutstandingChunksToProcess
)
{...}