typedef struct _ACX_CIRCUIT_TEMPLATE_CONFIG {
  ULONG            Size;
  ULONG            Flags;
  const GUID       *ContainerId;
  ACXOBJECTBAG     FactoryProperties;
  const GUID       *FactoryId;
  PCUNICODE_STRING FactoryUri;
  PCUNICODE_STRING FactoryName;
  ACXOBJECTBAG     CircuitProperties;
  const GUID       *CircuitId;
  PCUNICODE_STRING CircuitUri;
  PCUNICODE_STRING CircuitName;
} ACX_CIRCUIT_TEMPLATE_CONFIG, *PACX_CIRCUIT_TEMPLATE_CONFIG;