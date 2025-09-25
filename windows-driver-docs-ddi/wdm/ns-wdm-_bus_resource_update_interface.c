typedef struct _BUS_RESOURCE_UPDATE_INTERFACE {
  USHORT                    Size;
  USHORT                    Version;
  PVOID                     Context;
  PINTERFACE_REFERENCE      InterfaceReference;
  PINTERFACE_DEREFERENCE    InterfaceDereference;
  PGET_UPDATED_BUS_RESOURCE GetUpdatedBusResource;
} BUS_RESOURCE_UPDATE_INTERFACE, *PBUS_RESOURCE_UPDATE_INTERFACE;