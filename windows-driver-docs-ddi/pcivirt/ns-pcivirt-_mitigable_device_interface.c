typedef struct _MITIGABLE_DEVICE_INTERFACE {
  USHORT                         Size;
  USHORT                         Version;
  PVOID                          Context;
  PINTERFACE_REFERENCE           InterfaceReference;
  PINTERFACE_REFERENCE           InterfaceDereference;
  PREAD_WRITE_MITIGATED_REGISTER ReadWriteMitigatedRegister;
} MITIGABLE_DEVICE_INTERFACE, MITIGABLE_DEVICE_INTERFACE;