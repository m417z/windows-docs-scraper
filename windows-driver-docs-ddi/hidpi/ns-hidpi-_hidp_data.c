typedef struct _HIDP_DATA {
  USHORT DataIndex;
  USHORT Reserved;
  union {
    ULONG   RawValue;
    BOOLEAN On;
  };
} HIDP_DATA, *PHIDP_DATA;