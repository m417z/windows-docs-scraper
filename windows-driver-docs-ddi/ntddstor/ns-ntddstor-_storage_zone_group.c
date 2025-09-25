typedef struct _STORAGE_ZONE_GROUP {
  ULONG              ZoneCount;
  STORAGE_ZONE_TYPES ZoneType;
  ULONGLONG          ZoneSize;
} STORAGE_ZONE_GROUP, *PSTORAGE_ZONE_GROUP;