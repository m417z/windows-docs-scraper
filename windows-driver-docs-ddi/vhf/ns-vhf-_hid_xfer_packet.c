typedef struct _HID_XFER_PACKET {
  PUCHAR reportBuffer;
  ULONG  reportBufferLen;
  UCHAR  reportId;
} HID_XFER_PACKET, *PHID_XFER_PACKET;