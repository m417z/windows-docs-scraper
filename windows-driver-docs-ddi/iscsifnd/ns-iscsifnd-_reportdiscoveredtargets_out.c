typedef struct _ReportDiscoveredTargets_OUT {
  ULONG                  Status;
  ULONG                  TargetCount;
  ISCSI_DiscoveredTarget Targets[1];
} ReportDiscoveredTargets_OUT, *PReportDiscoveredTargets_OUT;