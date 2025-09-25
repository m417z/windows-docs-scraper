typedef struct HBA_ipaddress {
  int   ipversion;
  union {
    unsigned char ipv4address[4];
    unsigned char ipv6address[16];
  } ipaddress;
} HBA_IPADDRESS, *PHBA_IPADDRESS;