typedef struct icmpv6_echo_reply_lh {
  IPV6_ADDRESS_EX Address;
  ULONG           Status;
  unsigned int    RoundTripTime;
} ICMPV6_ECHO_REPLY_LH, *PICMPV6_ECHO_REPLY_LH;