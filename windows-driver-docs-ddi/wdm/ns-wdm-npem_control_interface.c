typedef struct _NPEM_CONTROL_INTERFACE {
  USHORT                                    Size;
  USHORT                                    Version;
  PVOID                                     Context;
  PINTERFACE_REFERENCE                      InterfaceReference;
  PINTERFACE_DEREFERENCE                    InterfaceDereference;
  PNPEM_CONTROL_ENABLE_DISABLE              SetNpemSupportState;
  PNPEM_CONTROL_QUERY_STANDARD_CAPABILITIES QueryStandardCapabilities;
  PNPEM_CONTROL_SET_STANDARD_CONTROL        SetStandardControl;
  PNPEM_CONTROL_QUERY_CONTROL               QueryNpemControl;
} NPEM_CONTROL_INTERFACE, *PNPEM_CONTROL_INTERFACE;