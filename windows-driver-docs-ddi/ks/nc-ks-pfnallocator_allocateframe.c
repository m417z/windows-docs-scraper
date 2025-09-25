PFNALLOCATOR_ALLOCATEFRAME PfnallocatorAllocateframe;

NTSTATUS PfnallocatorAllocateframe(
  [in]  PFILE_OBJECT FileObject,
  [out] PVOID *Frame
)
{...}