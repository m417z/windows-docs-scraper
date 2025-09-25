typedef struct _STORAGE_PROTOCOL_SPECIFIC_DATA {
  STORAGE_PROTOCOL_TYPE ProtocolType;
  ULONG                 DataType;
  ULONG                 ProtocolDataRequestValue;
  ULONG                 ProtocolDataRequestSubValue;
  ULONG                 ProtocolDataOffset;
  ULONG                 ProtocolDataLength;
  ULONG                 FixedProtocolReturnData;
  ULONG                 ProtocolDataRequestSubValue2;
  ULONG                 ProtocolDataRequestSubValue3;
  ULONG                 ProtocolDataRequestSubValue4;
} STORAGE_PROTOCOL_SPECIFIC_DATA, *PSTORAGE_PROTOCOL_SPECIFIC_DATA;