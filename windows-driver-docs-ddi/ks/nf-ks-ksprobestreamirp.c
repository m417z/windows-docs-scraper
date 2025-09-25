KSDDKAPI NTSTATUS KsProbeStreamIrp(
  [in, out]      PIRP  Irp,
  [in]           ULONG ProbeFlags,
  [in, optional] ULONG HeaderSize
);