typedef struct _INTERFACE_TIMESTAMP_CAPABILITIES {
  ULONG64                                   HardwareClockFrequencyHz;
  BOOLEAN                                   SupportsCrossTimestamp;
  INTERFACE_HARDWARE_TIMESTAMP_CAPABILITIES HardwareCapabilities;
  INTERFACE_SOFTWARE_TIMESTAMP_CAPABILITIES SoftwareCapabilities;
} INTERFACE_TIMESTAMP_CAPABILITIES, *PINTERFACE_TIMESTAMP_CAPABILITIES;