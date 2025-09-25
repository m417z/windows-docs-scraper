typedef struct _DXGKARGCB_ISFEATUREENABLED {
  HANDLE          DeviceHandle;
  DXGK_FEATURE_ID FeatureId;
  BOOLEAN         Enabled;
} DXGKARGCB_ISFEATUREENABLED;