NTSTATUS GetModes(
  [in]            ULONG Pin,
  [out, optional] GUID  *SignalProcessingModes,
  [in, out]       ULONG *NumSignalProcessingModes
);