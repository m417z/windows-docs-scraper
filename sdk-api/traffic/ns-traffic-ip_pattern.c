typedef struct _IP_PATTERN {
  ULONG Reserved1;
  ULONG Reserved2;
  ULONG SrcAddr;
  ULONG DstAddr;
  union {
    struct {
      USHORT s_srcport;
      USHORT s_dstport;
    } S_un_ports;
    struct {
      UCHAR  s_type;
      UCHAR  s_code;
      USHORT filler;
    } S_un_icmp;
    ULONG S_Spi;
  } S_un;
  UCHAR ProtocolId;
  UCHAR Reserved3[3];
} IP_PATTERN, *PIP_PATTERN;