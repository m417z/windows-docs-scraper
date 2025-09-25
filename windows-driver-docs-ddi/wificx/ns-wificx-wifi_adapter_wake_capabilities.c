typedef struct _WIFI_ADAPTER_WAKE_CAPABILITIES {
  ULONG   Size;
  BOOLEAN NloDiscovery;
  BOOLEAN ApAssociationLost;
  BOOLEAN GtkHandshakeError;
  BOOLEAN FourWayHandshakeRequest;
  BOOLEAN IncomingActionFrame;
  BOOLEAN ClientDriverDiagnostic;
} WIFI_ADAPTER_WAKE_CAPABILITIES;