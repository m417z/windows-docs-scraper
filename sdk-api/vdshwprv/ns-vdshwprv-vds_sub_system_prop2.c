typedef struct _VDS_SUB_SYSTEM_PROP2 {
  VDS_OBJECT_ID         id;
  LPWSTR                pwszFriendlyName;
  LPWSTR                pwszIdentification;
  ULONG                 ulFlags;
  ULONG                 ulStripeSizeFlags;
  ULONG                 ulSupportedRaidTypeFlags;
  VDS_SUB_SYSTEM_STATUS status;
  VDS_HEALTH            health;
  SHORT                 sNumberOfInternalBuses;
  SHORT                 sMaxNumberOfSlotsEachBus;
  SHORT                 sMaxNumberOfControllers;
  SHORT                 sRebuildPriority;
  ULONG                 ulNumberOfEnclosures;
} VDS_SUB_SYSTEM_PROP2, *PVDS_SUB_SYSTEM_PROP2;