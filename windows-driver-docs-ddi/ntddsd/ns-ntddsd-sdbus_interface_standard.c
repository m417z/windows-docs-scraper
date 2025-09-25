typedef struct _SDBUS_INTERFACE_STANDARD {
  USHORT                              Size;
  USHORT                              Version;
  PVOID                               Context;
  PINTERFACE_REFERENCE                InterfaceReference;
  PINTERFACE_DEREFERENCE              InterfaceDereference;
  PSDBUS_INITIALIZE_INTERFACE_ROUTINE InitializeInterface;
  PSDBUS_ACKNOWLEDGE_INT_ROUTINE      AcknowledgeInterrupt;
} SDBUS_INTERFACE_STANDARD, *PSDBUS_INTERFACE_STANDARD;