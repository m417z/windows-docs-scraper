typedef struct _ACCESS_ALLOWED_ACE {
  ACE_HEADER  Header;
  ACCESS_MASK Mask;
  ULONG       SidStart;
} ACCESS_ALLOWED_ACE;