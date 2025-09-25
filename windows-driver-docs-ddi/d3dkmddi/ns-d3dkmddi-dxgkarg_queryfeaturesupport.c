typedef struct _DXGKARG_QUERYFEATURESUPPORT {
  DXGK_FEATURE_ID      FeatureId;
  DXGK_FEATURE_VERSION MinSupportedVersion;
  DXGK_FEATURE_VERSION MaxSupportedVersion;
  BOOLEAN              AllowExperimental;
  BOOLEAN              SupportedByDriver;
  BOOLEAN              SupportedOnCurrentConfig;
} DXGKARG_QUERYFEATURESUPPORT;