typedef struct APOInitSystemEffects {
  APOInitBaseStruct   APOInit;
  IPropertyStore      *pAPOEndpointProperties;
  IPropertyStore      *pAPOSystemEffectsProperties;
  void                *pReserved;
  IMMDeviceCollection *pDeviceCollection;
} APOInitSystemEffects;