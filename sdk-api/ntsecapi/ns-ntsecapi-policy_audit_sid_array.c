typedef struct _POLICY_AUDIT_SID_ARRAY {
  ULONG          UsersCount;
#if ...
  PAUDIT_SID_RPC *UserSidArray;
#else
  PSID           *UserSidArray;
#endif
} POLICY_AUDIT_SID_ARRAY, *PPOLICY_AUDIT_SID_ARRAY;