typedef struct icmp_echo_reply32 {
  IPAddr                         Address;
  ULONG                          Status;
  ULONG                          RoundTripTime;
  USHORT                         DataSize;
  USHORT                         Reserved;
  VOID POINTER_32                           *Data;
  struct ip_option_information32 Options;
} ICMP_ECHO_REPLY32, *PICMP_ECHO_REPLY32;