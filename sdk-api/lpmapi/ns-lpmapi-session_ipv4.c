typedef struct {
  IN_ADDR sess_destaddr;
  UCHAR   sess_protid;
  UCHAR   sess_flags;
  USHORT  sess_destport;
} Session_IPv4;