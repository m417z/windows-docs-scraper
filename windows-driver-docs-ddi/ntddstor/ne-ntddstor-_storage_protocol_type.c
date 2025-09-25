typedef enum _STORAGE_PROTOCOL_TYPE {
  ProtocolTypeUnknown,
  ProtocolTypeScsi,
  ProtocolTypeAta,
  ProtocolTypeNvme,
  ProtocolTypeSd,
  ProtocolTypeUfs,
  ProtocolTypeProprietary,
  ProtocolTypeMaxReserved
} STORAGE_PROTOCOL_TYPE, *PSTORAGE_PROTOCOL_TYPE;