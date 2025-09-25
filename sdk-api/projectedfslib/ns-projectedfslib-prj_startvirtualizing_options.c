typedef struct PRJ_STARTVIRTUALIZING_OPTIONS {
  PRJ_STARTVIRTUALIZING_FLAGS Flags;
  UINT32                      PoolThreadCount;
  UINT32                      ConcurrentThreadCount;
  PRJ_NOTIFICATION_MAPPING    *NotificationMappings;
  UINT32                      NotificationMappingsCount;
} PRJ_STARTVIRTUALIZING_OPTIONS;