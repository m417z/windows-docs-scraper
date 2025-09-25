typedef struct {
  ULONG Size;
  ULONG Version;
  ULONG MaximumHorizontalUncertainty;
  ULONG MinDistanceBetweenFixes;
  ULONG MaximumErrorTimeoutMs;
  BYTE  Unused[512];
} GNSS_BREADCRUMBING_PARAM, *PGNSS_BREADCRUMBING_PARAM;