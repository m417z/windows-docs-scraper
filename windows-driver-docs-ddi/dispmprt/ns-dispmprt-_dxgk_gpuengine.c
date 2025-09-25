typedef struct _DXGK_GPUENGINE {
  DXGK_ENGINE_TYPE EngineType;
  WCHAR            Name[DXGK_MAX_METADATA_NAME_LENGTH];
  ULONG            NumPartitionUnits;
} DXGK_GPUENGINE, *PDXGK_GPUENGINE;