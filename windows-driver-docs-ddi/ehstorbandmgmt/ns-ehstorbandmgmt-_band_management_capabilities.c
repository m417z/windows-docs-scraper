typedef struct _BAND_MANAGEMENT_CAPABILITIES {
  ULONG     StructSize;
  ULONG     Capabilities;
  ULONGLONG KeyProtectionMechanism;
  ULONG     MinAuthKeyLength;
  ULONG     MaxAuthKeyLength;
  ULONG     MaxBandCount;
  ULONG     MaxSimultaneousReencryptionCount;
  ULONG     BandMetadataSize;
} BAND_MANAGEMENT_CAPABILITIES, *PBAND_MANAGEMENT_CAPABILITIES;