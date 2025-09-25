typedef enum _STORAGE_PROTOCOL_TYPE {
  ProtocolTypeUnknown = 0x00,
  ProtocolTypeScsi,
  ProtocolTypeAta,
  ProtocolTypeNvme,
  ProtocolTypeSd,
  ProtocolTypeUfs,
  ProtocolTypeProprietary = 0x7E,
  ProtocolTypeMaxReserved = 0x7F
} STORAGE_PROTOCOL_TYPE, *PSTORAGE_PROTOCOL_TYPE;