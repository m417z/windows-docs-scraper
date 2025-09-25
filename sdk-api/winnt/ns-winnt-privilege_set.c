typedef struct _PRIVILEGE_SET {
  DWORD               PrivilegeCount;
  DWORD               Control;
  LUID_AND_ATTRIBUTES Privilege[ANYSIZE_ARRAY];
} PRIVILEGE_SET, *PPRIVILEGE_SET;