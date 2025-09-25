typedef union sockaddr_gen {
  struct sockaddr         Address;
  struct sockaddr_in      AddressIn;
  struct sockaddr_in6_old AddressIn6;
} sockaddr_gen;