typedef struct AUDIO_SYSTEMEFFECTS_PROPERTY_CHANGE_NOTIFICATION {
  IMMDevice                              *endpoint;
  GUID                                   propertyStoreContext;
  AUDIO_SYSTEMEFFECTS_PROPERTYSTORE_TYPE propertyStoreType;
  IPropertyStore                         *propertyStore;
  PROPERTYKEY                            propertyKey;
} AUDIO_SYSTEMEFFECTS_PROPERTY_CHANGE_NOTIFICATION;