typedef struct _TOKEN_GROUPS_AND_PRIVILEGES {
  ULONG                SidCount;
  ULONG                SidLength;
  PSID_AND_ATTRIBUTES  Sids;
  ULONG                RestrictedSidCount;
  ULONG                RestrictedSidLength;
  PSID_AND_ATTRIBUTES  RestrictedSids;
  ULONG                PrivilegeCount;
  ULONG                PrivilegeLength;
  PLUID_AND_ATTRIBUTES Privileges;
  LUID                 AuthenticationId;
} TOKEN_GROUPS_AND_PRIVILEGES, *PTOKEN_GROUPS_AND_PRIVILEGES;