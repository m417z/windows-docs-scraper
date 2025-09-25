KSDDKAPI NTSTATUS KsTopologyPropertyHandler(
  [in]      PIRP             Irp,
  [in]      PKSPROPERTY      Property,
  [in, out] PVOID            Data,
  [in]      const KSTOPOLOGY *Topology
);