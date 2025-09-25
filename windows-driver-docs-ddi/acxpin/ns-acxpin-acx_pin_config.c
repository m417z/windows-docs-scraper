typedef struct _ACX_PIN_CONFIG {
  ULONG                 Size;
  ULONG                 Flags;
  ULONG                 Id;
  ACX_PIN_TYPE          Type;
  ACX_PIN_COMMUNICATION Communication;
  ACX_PIN_QUALIFIER     Qualifier;
  const GUID            *Category;
  const GUID            *Name;
  PACX_PIN_CALLBACKS    PinCallbacks;
  ULONG                 PropertiesCount;
  ULONG                 MethodsCount;
  PACX_PROPERTY_ITEM    Properties;
  PACX_METHOD_ITEM      Methods;
  union {
    PACX_MICROPHONE_CONFIG MicrophoneConfig;
  } u;
  ULONG                 MaxStreams;
} ACX_PIN_CONFIG, *PACX_PIN_CONFIG;