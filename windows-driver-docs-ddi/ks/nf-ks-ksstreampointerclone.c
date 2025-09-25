KSDDKAPI NTSTATUS KsStreamPointerClone(
  [in]           PKSSTREAM_POINTER  StreamPointer,
  [in, optional] PFNKSSTREAMPOINTER CancelCallback,
  [in]           ULONG              ContextSize,
  [out]          PKSSTREAM_POINTER  *CloneStreamPointer
);