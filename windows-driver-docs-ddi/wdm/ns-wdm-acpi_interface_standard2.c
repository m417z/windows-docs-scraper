typedef struct {
  USHORT                                Size;
  USHORT                                Version;
  PVOID                                 Context;
  PINTERFACE_REFERENCE                  InterfaceReference;
  PINTERFACE_DEREFERENCE                InterfaceDereference;
  PGPE_CONNECT_VECTOR2                  GpeConnectVector;
  PGPE_DISCONNECT_VECTOR2               GpeDisconnectVector;
  PGPE_ENABLE_EVENT2                    GpeEnableEvent;
  PGPE_DISABLE_EVENT2                   GpeDisableEvent;
  PGPE_CLEAR_STATUS2                    GpeClearStatus;
  PREGISTER_FOR_DEVICE_NOTIFICATIONS2   RegisterForDeviceNotifications;
  PUNREGISTER_FOR_DEVICE_NOTIFICATIONS2 UnregisterForDeviceNotifications;
} ACPI_INTERFACE_STANDARD2, *PACPI_INTERFACE_STANDARD2;