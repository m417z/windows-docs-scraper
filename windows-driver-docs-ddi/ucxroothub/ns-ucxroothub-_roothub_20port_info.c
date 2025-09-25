typedef struct _ROOTHUB_20PORT_INFO {
  USHORT                               PortNumber;
  UCHAR                                MinorRevision;
  UCHAR                                HubDepth;
  TRISTATE                             Removable;
  TRISTATE                             IntegratedHubImplemented;
  TRISTATE                             DebugCapable;
  CONTROLLER_USB_20_HARDWARE_LPM_FLAGS ControllerUsb20HardwareLpmFlags;
} ROOTHUB_20PORT_INFO, *PROOTHUB_20PORT_INFO;