typedef struct _ACCESS_DENIED_ACE {
  ACE_HEADER  Header;
  ACCESS_MASK Mask;
  DWORD       SidStart;
} ACCESS_DENIED_ACE;