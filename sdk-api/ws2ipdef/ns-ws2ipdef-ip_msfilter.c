typedef struct ip_msfilter {
  IN_ADDR             imsf_multiaddr;
  IN_ADDR             imsf_interface;
  MULTICAST_MODE_TYPE imsf_fmode;
  ULONG               imsf_numsrc;
  IN_ADDR             imsf_slist[1];
} IP_MSFILTER, *PIP_MSFILTER;