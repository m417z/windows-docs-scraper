typedef struct _DXGKARGCB_QUERYFEATURESUPPORT {
  HANDLE          DeviceHandle;
  DXGK_FEATURE_ID FeatureId;
  UINT            DriverSupportState;
  BOOLEAN         Enabled;
} DXGKARGCB_QUERYFEATURESUPPORT;