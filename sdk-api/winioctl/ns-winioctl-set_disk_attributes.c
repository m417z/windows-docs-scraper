typedef struct _SET_DISK_ATTRIBUTES {
  DWORD     Version;
  BOOLEAN   Persist;
  BYTE      Reserved1[3];
  DWORDLONG Attributes;
  DWORDLONG AttributesMask;
  DWORD     Reserved2[4];
} SET_DISK_ATTRIBUTES, *PSET_DISK_ATTRIBUTES;