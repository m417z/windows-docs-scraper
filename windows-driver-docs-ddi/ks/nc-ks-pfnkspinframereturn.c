PFNKSPINFRAMERETURN Pfnkspinframereturn;

void Pfnkspinframereturn(
  [in]           PKSPIN Pin,
  [in, optional] PVOID Data,
  [in, optional] ULONG Size,
  [in, optional] PMDL Mdl,
  [in, optional] PVOID Context,
  [in]           NTSTATUS Status
)
{...}