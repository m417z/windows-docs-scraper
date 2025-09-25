typedef struct ip_mreq {
  IN_ADDR imr_multiaddr;
  IN_ADDR imr_interface;
} IP_MREQ, *PIP_MREQ;