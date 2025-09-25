PFNKSPININITIALIZEALLOCATOR Pfnkspininitializeallocator;

NTSTATUS Pfnkspininitializeallocator(
  [in]  PKSPIN Pin,
  [in]  PKSALLOCATOR_FRAMING AllocatorFraming,
  [out] PVOID *Context
)
{...}