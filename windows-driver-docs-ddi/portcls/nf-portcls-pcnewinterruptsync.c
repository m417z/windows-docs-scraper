PORTCLASSAPI NTSTATUS PcNewInterruptSync(
  [out]          PINTERRUPTSYNC    *OutInterruptSync,
  [in, optional] PUNKNOWN          OuterUnknown,
  [in]           PRESOURCELIST     ResourceList,
  [in]           ULONG             ResourceIndex,
  [in]           INTERRUPTSYNCMODE Mode
);