typedef struct _TOKEN_GROUPS_AND_PRIVILEGES {
  DWORD                SidCount;
  DWORD                SidLength;
  PSID_AND_ATTRIBUTES  Sids;
  DWORD                RestrictedSidCount;
  DWORD                RestrictedSidLength;
  PSID_AND_ATTRIBUTES  RestrictedSids;
  DWORD                PrivilegeCount;
  DWORD                PrivilegeLength;
  PLUID_AND_ATTRIBUTES Privileges;
  LUID                 AuthenticationId;
} TOKEN_GROUPS_AND_PRIVILEGES, *PTOKEN_GROUPS_AND_PRIVILEGES;