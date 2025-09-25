PPHYSICAL_COUNTER_EVENT_BUFFER_OVERFLOW_HANDLER PphysicalCounterEventBufferOverflowHandler;

VOID PphysicalCounterEventBufferOverflowHandler(
  PVOID EventBuffer,
  SIZE_T EntrySize,
  SIZE_T NumberOfEntries,
  HANDLE OwningHandle
)
{...}