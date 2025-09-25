KSDDKAPI NTSTATUS KsMethodHandler(
  [in] PIRP               Irp,
  [in] ULONG              MethodSetsCount,
  [in] const KSMETHOD_SET *MethodSet
);