typedef struct _CREDUIWIN_MARSHALED_CONTEXT {
  GUID   StructureType;
  USHORT cbHeaderLength;
  LUID   LogonId;
  GUID   MarshaledDataType;
  ULONG  MarshaledDataOffset;
  USHORT MarshaledDataLength;
} CREDUIWIN_MARSHALED_CONTEXT, *PCREDUIWIN_MARSHALED_CONTEXT;