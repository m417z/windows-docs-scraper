PFNKSIRPLISTCALLBACK Pfnksirplistcallback;

NTSTATUS Pfnksirplistcallback(
  [in] PIRP Irp,
  [in] PVOID Context
)
{...}