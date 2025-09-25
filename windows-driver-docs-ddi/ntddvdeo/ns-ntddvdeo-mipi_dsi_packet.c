typedef struct _MIPI_DSI_PACKET {
  union {
    UCHAR DataId;
    struct {
      UCHAR DataType : 6;
      UCHAR VirtualChannel : 2;
    };
  };
  union {
    struct {
      UCHAR Data0;
      UCHAR Data1;
    };
    USHORT LongWriteWordCount;
  };
  UCHAR EccFiller;
  UCHAR Payload[DSI_PACKET_EMBEDDED_PAYLOAD_SIZE];
} MIPI_DSI_PACKET;