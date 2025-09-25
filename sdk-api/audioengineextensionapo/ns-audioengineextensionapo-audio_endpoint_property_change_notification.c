typedef struct AUDIO_ENDPOINT_PROPERTY_CHANGE_NOTIFICATION {
  IMMDevice      *endpoint;
  IPropertyStore *propertyStore;
  PROPERTYKEY    propertyKey;
} AUDIO_ENDPOINT_PROPERTY_CHANGE_NOTIFICATION;