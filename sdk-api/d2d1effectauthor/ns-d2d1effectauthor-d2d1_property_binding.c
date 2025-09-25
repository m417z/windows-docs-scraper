typedef struct D2D1_PROPERTY_BINDING {
  PCWSTR                      propertyName;
  PD2D1_PROPERTY_SET_FUNCTION setFunction;
  PD2D1_PROPERTY_GET_FUNCTION getFunction;
} D2D1_PROPERTY_BINDING;