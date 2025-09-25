BOOLEAN ScsiPortWmiSetInstanceCount(
  [in]  PSCSIWMI_REQUEST_CONTEXT RequestContext,
  [in]  ULONG                    InstanceCount,
  [out] PULONG                   BufferAvail,
  [out] PULONG                   SizeNeeded
);