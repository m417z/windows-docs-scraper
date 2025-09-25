typedef struct group_filter {
  ULONG               gf_interface;
  SOCKADDR_STORAGE    gf_group;
  MULTICAST_MODE_TYPE gf_fmode;
  ULONG               gf_numsrc;
  SOCKADDR_STORAGE    gf_slist[1];
} GROUP_FILTER, *PGROUP_FILTER;