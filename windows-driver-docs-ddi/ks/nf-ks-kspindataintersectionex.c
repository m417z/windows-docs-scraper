KSDDKAPI NTSTATUS KsPinDataIntersectionEx(
  [in]           PIRP                    Irp,
  [in]           PKSP_PIN                Pin,
  [out]          PVOID                   Data,
  [in]           ULONG                   DescriptorsCount,
  [in]           const KSPIN_DESCRIPTOR  *Descriptor,
  [in]           ULONG                   DescriptorSize,
  [in, optional] PFNKSINTERSECTHANDLEREX IntersectHandler,
  [in, optional] PVOID                   HandlerContext
);