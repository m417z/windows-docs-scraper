typedef struct in_addr {
  union {
    struct {
      UCHAR s_b1;
      UCHAR s_b2;
      UCHAR s_b3;
      UCHAR s_b4;
    } S_un_b;
    struct {
      USHORT s_w1;
      USHORT s_w2;
    } S_un_w;
    ULONG S_addr;
  } S_un;
} IN_ADDR, *PIN_ADDR, *LPIN_ADDR;