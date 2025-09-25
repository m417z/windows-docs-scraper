typedef struct _VDS_SUB_SYSTEM_PROP {
  VDS_OBJECT_ID         id;
  LPWSTR                pwszFriendlyName;
  LPWSTR                pwszIdentification;
  ULONG                 ulFlags;
  ULONG                 ulStripeSizeFlags;
  VDS_SUB_SYSTEM_STATUS status;
  VDS_HEALTH            health;
  SHORT                 sNumberOfInternalBuses;
  SHORT                 sMaxNumberOfSlotsEachBus;
  SHORT                 sMaxNumberOfControllers;
  SHORT                 sRebuildPriority;
} VDS_SUB_SYSTEM_PROP, *PVDS_SUB_SYSTEM_PROP;