typedef struct ip_mreq_source {
  IN_ADDR imr_multiaddr;
  IN_ADDR imr_sourceaddr;
  IN_ADDR imr_interface;
} IP_MREQ_SOURCE, *PIP_MREQ_SOURCE;