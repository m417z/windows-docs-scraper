typedef struct _PEP_INFORMATION {
  USHORT                 Version;
  USHORT                 Size;
  PPEPCALLBACKNOTIFYDPM  AcceptDeviceNotification;
  PPEPCALLBACKNOTIFYPPM  AcceptProcessorNotification;
  PPEPCALLBACKNOTIFYACPI AcceptAcpiNotification;
} PEP_INFORMATION, *PPEP_INFORMATION;