typedef struct _DXGKARGCB_QUERYFEATUREINTERFACE {
  DXGK_FEATURE_ID      FeatureId;
  DXGK_FEATURE_VERSION Version;
  UINT16               InterfaceSize;
  void                 *Interface;
} DXGKARGCB_QUERYFEATUREINTERFACE;