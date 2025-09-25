typedef struct _ACCESS_DENIED_ACE {
  ACE_HEADER  Header;
  ACCESS_MASK Mask;
  ULONG       SidStart;
} ACCESS_DENIED_ACE;