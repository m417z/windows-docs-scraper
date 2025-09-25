PFNKSHANDLER Pfnkshandler;

NTSTATUS Pfnkshandler(
  [in]      PIRP Irp,
  [in]      PKSIDENTIFIER Request,
  [in, out] PVOID Data
)
{...}