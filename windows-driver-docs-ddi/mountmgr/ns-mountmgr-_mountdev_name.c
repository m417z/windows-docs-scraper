typedef struct _MOUNTDEV_NAME {
  USHORT NameLength;
  WCHAR  Name[1];
} MOUNTDEV_NAME, *PMOUNTDEV_NAME;