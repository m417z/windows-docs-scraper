typedef struct _VDS_STORAGE_POOL_PROP {
  VDS_OBJECT_ID           id;
  VDS_STORAGE_POOL_STATUS status;
  VDS_HEALTH              health;
  VDS_STORAGE_POOL_TYPE   type;
  LPWSTR                  pwszName;
  LPWSTR                  pwszDescription;
  ULONGLONG               ullTotalConsumedSpace;
  ULONGLONG               ullTotalManagedSpace;
  ULONGLONG               ullRemainingFreeSpace;
} VDS_STORAGE_POOL_PROP, *PVDS_STORAGE_POOL_PROP;