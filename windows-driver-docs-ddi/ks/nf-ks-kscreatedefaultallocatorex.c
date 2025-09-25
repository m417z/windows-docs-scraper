KSDDKAPI NTSTATUS KsCreateDefaultAllocatorEx(
  [in]           PIRP                     Irp,
  [in, optional] PVOID                    InitializeContext,
  [in, optional] PFNKSDEFAULTALLOCATE     DefaultAllocate,
  [in, optional] PFNKSDEFAULTFREE         DefaultFree,
  [in, optional] PFNKSINITIALIZEALLOCATOR InitializeAllocator,
  [in, optional] PFNKSDELETEALLOCATOR     DeleteAllocator
);