typedef struct _DXGKARG_QUERYFEATUREINTERFACE {
  DXGK_FEATURE_ID      FeatureId;
  DXGK_FEATURE_VERSION Version;
  UINT16               InterfaceSize;
  void                 *Interface;
} DXGKARG_QUERYFEATUREINTERFACE;