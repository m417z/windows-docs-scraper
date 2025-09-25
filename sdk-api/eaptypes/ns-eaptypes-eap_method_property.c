typedef struct _EAP_METHOD_PROPERTY {
  EAP_METHOD_PROPERTY_TYPE       eapMethodPropertyType;
  EAP_METHOD_PROPERTY_VALUE_TYPE eapMethodPropertyValueType;
#if ...
  EAP_METHOD_PROPERTY_VALUE      eapMethodPropertyValue;
#else
  EAP_METHOD_PROPERTY_VALUE      eapMethodPropertyValue;
#endif
} EAP_METHOD_PROPERTY;