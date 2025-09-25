typedef struct _STORAGE_ZONE_DESCRIPTOR {
  ULONG                  Size;
  STORAGE_ZONE_TYPES     ZoneType;
  STORAGE_ZONE_CONDITION ZoneCondition;
  BOOLEAN                ResetWritePointerRecommend;
  UCHAR                  Reserved0[3];
  ULONGLONG              ZoneSize;
  ULONGLONG              WritePointerOffset;
} STORAGE_ZONE_DESCRIPTOR, *PSTORAGE_ZONE_DESCRIPTOR;