typedef union _PROC_TOPOLOGY_NODE_FLAGS {
  struct {
    ULONG PhysicalPackage : 1;
    ULONG ACPIProcessorIdValid : 1;
    ULONG ProcessorIsThread : 1;
    ULONG IsLeaf : 1;
    ULONG IdenticalImplementation : 1;
    ULONG Reserved : 27;
  };
  ULONG  AsULONG;
} PROC_TOPOLOGY_NODE_FLAGS, *PPROC_TOPOLOGY_NODE_FLAGS;