typedef struct _CLUS_MAINTENANCE_MODE_INFOEX {
  BOOL                       InMaintenance;
  MAINTENANCE_MODE_TYPE_ENUM MaintainenceModeType;
  CLUSTER_RESOURCE_STATE     InternalState;
  DWORD                      Signature;
} CLUS_MAINTENANCE_MODE_INFOEX, *PCLUS_MAINTENANCE_MODE_INFOEX;