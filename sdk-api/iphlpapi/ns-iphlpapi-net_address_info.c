typedef struct NET_ADDRESS_INFO_ {
  NET_ADDRESS_FORMAT Format;
  union {
    struct {
      WCHAR Address[DNS_MAX_NAME_BUFFER_LENGTH];
      WCHAR Port[6];
    } NamedAddress;
    SOCKADDR_IN  Ipv4Address;
    SOCKADDR_IN6 Ipv6Address;
    SOCKADDR     IpAddress;
  };
} NET_ADDRESS_INFO, *PNET_ADDRESS_INFO;