typedef struct _PMI_CAPABILITIES {
  ULONG                 Version;
  ULONG                 Size;
  PMI_CAPABILITIES_TYPE CapabilityType;
  union {
    PMI_REPORTED_CAPABILITIES        ReportedCapabilities;
    PMI_METERED_HARDWARE_INFORMATION MeteredHardwareInformation;
  } Capabilities;
} PMI_CAPABILITIES, *PPMI_CAPABILITIES;