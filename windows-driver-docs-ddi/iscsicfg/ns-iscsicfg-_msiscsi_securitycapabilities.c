typedef struct _MSiSCSI_SecurityCapabilities {
  BOOLEAN ProtectiScsiTraffic;
  BOOLEAN ProtectiSNSTraffic;
  BOOLEAN CertificatesSupported;
  ULONG   EncryptionAvailableCount;
  ULONG   EncryptionAvailable[1];
} MSiSCSI_SecurityCapabilities, *PMSiSCSI_SecurityCapabilities;