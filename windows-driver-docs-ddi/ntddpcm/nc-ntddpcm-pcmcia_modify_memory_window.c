PCMCIA_MODIFY_MEMORY_WINDOW PcmciaModifyMemoryWindow;

BOOLEAN PcmciaModifyMemoryWindow(
  [in, optional] PVOID Context,
  [in]           ULONGLONG HostBase,
  [in]           ULONGLONG CardBase,
  [in]           BOOLEAN Enable,
  [in, optional] ULONG WindowSize,
  [in, optional] UCHAR AccessSpeed,
  [in, optional] UCHAR BusWidth,
  [in, optional] BOOLEAN IsAttributeMemory
)
{...}