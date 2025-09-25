typedef struct _PRIVILEGE_SET {
  ULONG               PrivilegeCount;
  ULONG               Control;
  LUID_AND_ATTRIBUTES Privilege[ANYSIZE_ARRAY];
} PRIVILEGE_SET, *PPRIVILEGE_SET;