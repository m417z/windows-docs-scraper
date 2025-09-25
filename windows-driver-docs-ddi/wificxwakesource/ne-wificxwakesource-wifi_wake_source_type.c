typedef enum _WIFI_WAKE_SOURCE_TYPE {
  WifiWakeSourceTypeNloDiscovery,
  WifiWakeSourceTypeApAssociationLost,
  WifiWakeSourceTypeGtkHandshakeError,
  WifiWakeSourceTypeFourWayHandshakeRequest,
  WifiWakeSourceTypeIncomingActionFrame,
  WifiWakeSourceTypeClientDriverDiagnostic
} WIFI_WAKE_SOURCE_TYPE;