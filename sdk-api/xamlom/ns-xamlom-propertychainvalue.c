typedef struct PropertyChainValue {
  unsigned int Index;
  BSTR         Type;
  BSTR         DeclaringType;
  BSTR         ValueType;
  BSTR         ItemType;
  BSTR         Value;
  BOOL         Overridden;
  hyper        MetadataBits;
  BSTR         PropertyName;
  unsigned int PropertyChainIndex;
} PropertyChainValue;