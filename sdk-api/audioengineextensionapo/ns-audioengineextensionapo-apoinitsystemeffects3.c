typedef struct APOInitSystemEffects3 {
  APOInitBaseStruct   APOInit;
  IPropertyStore      *pAPOEndpointProperties;
  IServiceProvider    *pServiceProvider;
  IMMDeviceCollection *pDeviceCollection;
  UINT                nSoftwareIoDeviceInCollection;
  UINT                nSoftwareIoConnectorIndex;
  GUID                AudioProcessingMode;
  BOOL                InitializeForDiscoveryOnly;
} APOInitSystemEffects3;