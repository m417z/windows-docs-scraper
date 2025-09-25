KSDDKAPI NTSTATUS KsFilterAddTopologyConnections(
  [in] PKSFILTER                           Filter,
  [in] ULONG                               NewConnectionsCount,
  [in] const KSTOPOLOGY_CONNECTION * const NewTopologyConnections
);