typedef struct _ACX_ELEMENT_CONFIG {
  ULONG              Size;
  ULONG              Id;
  const GUID         *Type;
  const GUID         *Name;
  ULONG              Flags;
  ULONG              PropertiesCount;
  ULONG              MethodsCount;
  PACX_PROPERTY_ITEM Properties;
  PACX_METHOD_ITEM   Methods;
} ACX_ELEMENT_CONFIG, *PACX_ELEMENT_CONFIG;