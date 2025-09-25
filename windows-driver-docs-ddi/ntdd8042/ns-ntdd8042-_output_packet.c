typedef struct _OUTPUT_PACKET {
  PUCHAR         Bytes;
  ULONG          CurrentByte;
  ULONG          ByteCount;
  TRANSMIT_STATE State;
} OUTPUT_PACKET, *POUTPUT_PACKET;