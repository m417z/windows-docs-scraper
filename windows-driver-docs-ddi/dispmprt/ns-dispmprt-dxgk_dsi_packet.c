typedef struct _DXGK_DSI_PACKET {
  union {
    BYTE DataId;
    struct {
      BYTE DataType : 6;
      BYTE VirtualChannel : 2;
    };
  };
  union {
    struct {
      BYTE Data0;
      BYTE Data1;
    };
    WORD LongWriteWordCount;
  };
  BYTE  EccFiller;
  BYTE  Payload[DXGK_DSI_PACKET_EMBEDDED_PAYLOAD_SIZE];
} DXGK_DSI_PACKET, *PDXGK_DSI_PACKET;