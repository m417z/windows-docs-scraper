typedef struct _SendRNID_OUT {
  ULONG HBAStatus;
  ULONG ResponseBufferCount;
  UCHAR ResponseBuffer[1];
} SendRNID_OUT, *PSendRNID_OUT;