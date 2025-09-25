typedef struct _ReportDiscoveredTargets2_OUT {
  ULONG                   Status;
  ULONG                   TargetCount;
  ISCSI_DiscoveredTarget2 Targets[1];
} ReportDiscoveredTargets2_OUT, *PReportDiscoveredTargets2_OUT;