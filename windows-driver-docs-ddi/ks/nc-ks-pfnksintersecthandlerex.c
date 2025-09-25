PFNKSINTERSECTHANDLEREX Pfnksintersecthandlerex;

NTSTATUS Pfnksintersecthandlerex(
  [in]  PVOID Context,
  [in]  PIRP Irp,
  [in]  PKSP_PIN Pin,
  [in]  PKSDATARANGE DataRange,
  [in]  PKSDATARANGE MatchingDataRange,
  [in]  ULONG DataBufferSize,
  [out] PVOID Data,
  [out] PULONG DataSize
)
{...}