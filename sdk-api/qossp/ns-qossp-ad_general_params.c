typedef struct _AD_GENERAL_PARAMS {
  ULONG IntServAwareHopCount;
  ULONG PathBandwidthEstimate;
  ULONG MinimumLatency;
  ULONG PathMTU;
  ULONG Flags;
} AD_GENERAL_PARAMS, *LPAD_GENERAL_PARAMS;