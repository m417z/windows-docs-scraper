typedef struct _SYSTEM_AUDIT_ACE {
  ACE_HEADER  Header;
  ACCESS_MASK Mask;
  ULONG       SidStart;
} SYSTEM_AUDIT_ACE;