typedef struct _DXGK_ISFEATUREENABLED_RESULT {
  UINT16 Version;
  union {
    struct {
      UINT16 Enabled : 1;
      UINT16 KnownFeature : 1;
      UINT16 SupportedByDriver : 1;
      UINT16 SupportedOnCurrentConfig : 1;
      UINT16 Reserved : 12;
    };
    DXGK_FEATURE_VERSION Value;
  };
} DXGK_ISFEATUREENABLED_RESULT;