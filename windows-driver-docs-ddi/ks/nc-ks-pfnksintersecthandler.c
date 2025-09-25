PFNKSINTERSECTHANDLER Pfnksintersecthandler;

NTSTATUS Pfnksintersecthandler(
  [in]            PIRP Irp,
  [in]            PKSP_PIN Pin,
  [in]            PKSDATARANGE DataRange,
  [out, optional] PVOID Data
)
{...}