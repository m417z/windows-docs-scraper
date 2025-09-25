typedef struct _STORAGE_PROTOCOL_SPECIFIC_DATA {
  STORAGE_PROTOCOL_TYPE ProtocolType;
  DWORD                 DataType;
  DWORD                 ProtocolDataRequestValue;
  DWORD                 ProtocolDataRequestSubValue;
  DWORD                 ProtocolDataOffset;
  DWORD                 ProtocolDataLength;
  DWORD                 FixedProtocolReturnData;
  DWORD                 ProtocolDataRequestSubValue2;
  DWORD                 ProtocolDataRequestSubValue3;
  DWORD                 ProtocolDataRequestSubValue4;
} STORAGE_PROTOCOL_SPECIFIC_DATA, *PSTORAGE_PROTOCOL_SPECIFIC_DATA;