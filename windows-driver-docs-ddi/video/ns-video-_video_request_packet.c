typedef struct _VIDEO_REQUEST_PACKET {
  ULONG         IoControlCode;
  PSTATUS_BLOCK StatusBlock;
  PVOID         InputBuffer;
  ULONG         InputBufferLength;
  PVOID         OutputBuffer;
  ULONG         OutputBufferLength;
} VIDEO_REQUEST_PACKET, *PVIDEO_REQUEST_PACKET;