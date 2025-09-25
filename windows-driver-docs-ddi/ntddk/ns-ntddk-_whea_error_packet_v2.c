typedef struct _WHEA_ERROR_PACKET_V2 {
  ULONG                         Signature;
  ULONG                         Version;
  ULONG                         Length;
  WHEA_ERROR_PACKET_FLAGS       Flags;
  WHEA_ERROR_TYPE               ErrorType;
  WHEA_ERROR_SEVERITY           ErrorSeverity;
  ULONG                         ErrorSourceId;
  WHEA_ERROR_SOURCE_TYPE        ErrorSourceType;
  GUID                          NotifyType;
  ULONGLONG                     Context;
  WHEA_ERROR_PACKET_DATA_FORMAT DataFormat;
  ULONG                         Reserved1;
  ULONG                         DataOffset;
  ULONG                         DataLength;
  ULONG                         PshedDataOffset;
  ULONG                         PshedDataLength;
} WHEA_ERROR_PACKET_V2, *PWHEA_ERROR_PACKET_V2, WHEA_ERROR_PACKET, *PWHEA_ERROR_PACKET;