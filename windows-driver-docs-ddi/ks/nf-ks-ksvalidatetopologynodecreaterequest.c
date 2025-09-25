KSDDKAPI NTSTATUS KsValidateTopologyNodeCreateRequest(
  [in]  PIRP           Irp,
  [in]  PKSTOPOLOGY    Topology,
  [out] PKSNODE_CREATE *NodeCreate
);