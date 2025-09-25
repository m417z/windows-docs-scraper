typedef struct _ACX_FACTORY_CIRCUIT_ADD_CIRCUIT {
  ULONG            Size;
  ULONG            Flags;
  GUID             CircuitUniqueId;
  HANDLE           CompositeProperties;
  HANDLE           FactoryProperties;
  HANDLE           CircuitProperties;
  PCUNICODE_STRING TargetSymbolicLinkName;
} ACX_FACTORY_CIRCUIT_ADD_CIRCUIT, *PACX_FACTORY_CIRCUIT_ADD_CIRCUIT;