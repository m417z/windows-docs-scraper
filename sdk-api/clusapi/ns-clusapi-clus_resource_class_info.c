typedef struct CLUS_RESOURCE_CLASS_INFO {
  union {
    struct {
      union {
        DWORD                  dw;
        CLUSTER_RESOURCE_CLASS rc;
      } DUMMYUNIONNAME;
      DWORD SubClass;
    } DUMMYSTRUCTNAME;
    ULARGE_INTEGER li;
  } DUMMYUNIONNAME;
} CLUS_RESOURCE_CLASS_INFO, *PCLUS_RESOURCE_CLASS_INFO;