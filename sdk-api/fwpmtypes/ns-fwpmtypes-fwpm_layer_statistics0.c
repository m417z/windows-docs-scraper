typedef struct FWPM_LAYER_STATISTICS0_ {
  GUID   layerId;
  UINT32 classifyPermitCount;
  UINT32 classifyBlockCount;
  UINT32 classifyVetoCount;
  UINT32 numCacheEntries;
} FWPM_LAYER_STATISTICS0;