PSETUP_DMA_ENGINE_WITH_BDL PsetupDmaEngineWithBdl;

NTSTATUS PsetupDmaEngineWithBdl(
  [in]  PVOID _context,
  [in]  HANDLE Handle,
  [in]  ULONG BufferLength,
  [in]  ULONG Lvi,
  [in]  PHDAUDIO_BDL_ISR Isr,
  [in]  PVOID Context,
  [out] PUCHAR StreamId,
  [out] PULONG FifoSize
)
{...}