PSET_DMA_ENGINE_STATE PsetDmaEngineState;

NTSTATUS PsetDmaEngineState(
  [in] PVOID _context,
  [in] HDAUDIO_STREAM_STATE StreamState,
  [in] ULONG NumberOfHandles,
  [in] PHANDLE Handles
)
{...}