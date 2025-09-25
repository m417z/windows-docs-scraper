typedef struct _DXGKDDI_FEATURE_INTERFACE {
  USHORT                         Size;
  USHORT                         Version;
  PVOID                          Context;
  PINTERFACE_REFERENCE           InterfaceReference;
  PINTERFACE_DEREFERENCE         InterfaceDereference;
  PDXGKDDI_QUERYFEATURESUPPORT   QueryFeatureSupport;
  PDXGKDDI_QUERYFEATUREINTERFACE QueryFeatureInterface;
} DXGKDDI_FEATURE_INTERFACE, *PDXGKDDI_FEATURE_INTERFACE;