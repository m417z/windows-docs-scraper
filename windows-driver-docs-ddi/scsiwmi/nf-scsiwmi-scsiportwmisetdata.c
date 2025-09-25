PVOID ScsiPortWmiSetData(
  [in]      PSCSIWMI_REQUEST_CONTEXT RequestContext,
  [in]      ULONG                    InstanceIndex,
  [in]      ULONG                    DataLength,
  [out]     PULONG                   BufferAvail,
  [in, out] PULONG                   SizeNeeded
);