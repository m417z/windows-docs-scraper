typedef struct _URS_CONFIG {
  ULONG                                       Size;
  URS_HOST_INTERFACE_TYPE                     HostInterfaceType;
  PFN_URS_DEVICE_FILTER_RESOURCE_REQUIREMENTS EvtUrsFilterRemoveResourceRequirements;
  PFN_URS_SET_ROLE                            EvtUrsSetRole;
} URS_CONFIG, *PURS_CONFIG;