PWCHAR ScsiPortWmiSetInstanceName(
  [in]      PSCSIWMI_REQUEST_CONTEXT RequestContext,
  [in]      ULONG                    InstanceIndex,
  [in]      ULONG                    InstanceNameLength,
  [out]     PULONG                   BufferAvail,
  [in, out] PULONG                   SizeNeeded
);