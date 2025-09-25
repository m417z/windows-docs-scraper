struct in_addr {
  union {
    struct {
      u_char s_b1;
      u_char s_b2;
      u_char s_b3;
      u_char s_b4;
    } S_un_b;
    struct {
      u_short s_w1;
      u_short s_w2;
    } S_un_w;
    u_long S_addr;
  } S_un;
};