typedef struct group_source_req {
  ULONG            gsr_interface;
  SOCKADDR_STORAGE gsr_group;
  SOCKADDR_STORAGE gsr_source;
} GROUP_SOURCE_REQ, *PGROUP_SOURCE_REQ;