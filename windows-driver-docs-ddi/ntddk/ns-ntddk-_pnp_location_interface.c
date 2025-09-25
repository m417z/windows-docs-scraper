typedef struct _PNP_LOCATION_INTERFACE {
  USHORT                 Size;
  USHORT                 Version;
  PVOID                  Context;
  PINTERFACE_REFERENCE   InterfaceReference;
  PINTERFACE_DEREFERENCE InterfaceDereference;
  PGET_LOCATION_STRING   GetLocationString;
} PNP_LOCATION_INTERFACE, *PPNP_LOCATION_INTERFACE;