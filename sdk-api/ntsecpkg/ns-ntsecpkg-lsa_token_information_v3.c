typedef struct _LSA_TOKEN_INFORMATION_V3 {
  LARGE_INTEGER       ExpirationTime;
  TOKEN_USER          User;
  PTOKEN_GROUPS       Groups;
  TOKEN_PRIMARY_GROUP PrimaryGroup;
  PTOKEN_PRIVILEGES   Privileges;
  TOKEN_OWNER         Owner;
  TOKEN_DEFAULT_DACL  DefaultDacl;
  TOKEN_USER_CLAIMS   UserClaims;
  TOKEN_DEVICE_CLAIMS DeviceClaims;
  PTOKEN_GROUPS       DeviceGroups;
} LSA_TOKEN_INFORMATION_V3, *PLSA_TOKEN_INFORMATION_V3;