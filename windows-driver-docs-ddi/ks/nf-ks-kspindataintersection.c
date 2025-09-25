KSDDKAPI NTSTATUS KsPinDataIntersection(
  [in]            PIRP                   Irp,
  [in]            PKSP_PIN               Pin,
  [out, optional] PVOID                  Data,
  [in]            ULONG                  DescriptorsCount,
  [in]            const KSPIN_DESCRIPTOR *Descriptor,
  [in]            PFNKSINTERSECTHANDLER  IntersectHandler
);