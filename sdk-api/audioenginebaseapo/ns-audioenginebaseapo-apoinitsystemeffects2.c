typedef struct APOInitSystemEffects2 {
  APOInitBaseStruct   APOInit;
  IPropertyStore      *pAPOEndpointProperties;
  IPropertyStore      *pAPOSystemEffectsProperties;
  void                *pReserved;
  IMMDeviceCollection *pDeviceCollection;
  UINT                nSoftwareIoDeviceInCollection;
  UINT                nSoftwareIoConnectorIndex;
  GUID                AudioProcessingMode;
  BOOL                InitializeForDiscoveryOnly;
} APOInitSystemEffects2;