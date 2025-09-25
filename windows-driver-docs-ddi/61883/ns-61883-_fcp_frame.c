typedef struct _FCP_FRAME {
  UCHAR ctype : 4;
  UCHAR cts : 4;
  UCHAR payload[511];
} FCP_FRAME, *PFCP_FRAME;