KSDDKAPI NTSTATUS KsCreateTopologyNode(
  [in]  HANDLE         ParentHandle,
  [in]  PKSNODE_CREATE NodeCreate,
  [in]  ACCESS_MASK    DesiredAccess,
  [out] PHANDLE        NodeHandle
);