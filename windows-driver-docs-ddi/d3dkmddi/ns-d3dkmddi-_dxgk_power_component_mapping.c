typedef struct _DXGK_POWER_COMPONENT_MAPPING {
  DXGK_POWER_COMPONENT_TYPE ComponentType;
  union {
    struct {
      UINT NodeIndex;
    } EngineDesc;
    struct {
      UINT VidPnSourceID;
    } MonitorRefreshDesc;
    struct {
      UINT VidPnTargetID;
    } MonitorDesc;
    struct {
      UINT SegmentID;
    } MemoryDesc;
    struct {
      union {
        struct {
          WORD SharedTypeFlag;
          WORD DriverCustomValueSet;
        };
        UINT SharedType;
      };
    } SharedDesc;
  };
} DXGK_POWER_COMPONENT_MAPPING;