typedef struct _STORAGE_PROTOCOL_SPECIFIC_DATA_EXT {
  STORAGE_PROTOCOL_TYPE ProtocolType;
  ULONG                 DataType;
  ULONG                 ProtocolDataValue;
  ULONG                 ProtocolDataSubValue;
  ULONG                 ProtocolDataOffset;
  ULONG                 ProtocolDataLength;
  ULONG                 FixedProtocolReturnData;
  ULONG                 ProtocolDataSubValue2;
  ULONG                 ProtocolDataSubValue3;
  ULONG                 ProtocolDataSubValue4;
  ULONG                 ProtocolDataSubValue5;
  ULONG                 ProtocolDataSubValue6;
  ULONG                 Reserved[4];
} STORAGE_PROTOCOL_SPECIFIC_DATA_EXT, *PSTORAGE_PROTOCOL_SPECIFIC_DATA_EXT;