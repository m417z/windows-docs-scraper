typedef struct _SYSTEM_ALARM_ACE {
  ACE_HEADER  Header;
  ACCESS_MASK Mask;
  DWORD       SidStart;
} SYSTEM_ALARM_ACE;