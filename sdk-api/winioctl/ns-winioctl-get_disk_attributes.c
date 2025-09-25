typedef struct _GET_DISK_ATTRIBUTES {
  DWORD     Version;
  DWORD     Reserved1;
  DWORDLONG Attributes;
} GET_DISK_ATTRIBUTES, *PGET_DISK_ATTRIBUTES;