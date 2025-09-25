typedef struct _ACCESS_ALLOWED_ACE {
  ACE_HEADER  Header;
  ACCESS_MASK Mask;
  DWORD       SidStart;
} ACCESS_ALLOWED_ACE;