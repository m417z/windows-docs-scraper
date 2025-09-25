KSDDKAPI NTSTATUS KsStreamPointerAdvanceOffsets(
  [in] PKSSTREAM_POINTER StreamPointer,
  [in] ULONG             InUsed,
  [in] ULONG             OutUsed,
  [in] BOOLEAN           Eject
);