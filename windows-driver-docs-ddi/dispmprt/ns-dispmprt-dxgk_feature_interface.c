typedef struct _DXGK_FEATURE_INTERFACE {
  USHORT                       Size;
  USHORT                       Version;
  PVOID                        Context;
  PINTERFACE_REFERENCE         InterfaceReference;
  PINTERFACE_DEREFERENCE       InterfaceDereference;
  DXGKCB_ISFEATUREENABLED2     IsFeatureEnabled;
  DXGKCB_QUERYFEATUREINTERFACE QueryFeatureInterface;
} DXGK_FEATURE_INTERFACE, *PDXGK_FEATURE_INTERFACE;