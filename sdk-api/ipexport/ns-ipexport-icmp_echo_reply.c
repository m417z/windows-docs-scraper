typedef struct icmp_echo_reply {
  IPAddr                       Address;
  ULONG                        Status;
  ULONG                        RoundTripTime;
  USHORT                       DataSize;
  USHORT                       Reserved;
  PVOID                        Data;
  struct ip_option_information Options;
} ICMP_ECHO_REPLY, *PICMP_ECHO_REPLY;