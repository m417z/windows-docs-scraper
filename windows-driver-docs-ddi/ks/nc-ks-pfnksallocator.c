PFNKSALLOCATOR Pfnksallocator;

NTSTATUS Pfnksallocator(
  [in] PIRP Irp,
  [in] ULONG BufferSize,
  [in] BOOLEAN InputOperation
)
{...}