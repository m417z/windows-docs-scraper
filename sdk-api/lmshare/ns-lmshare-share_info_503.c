typedef struct _SHARE_INFO_503 {
  LMSTR                shi503_netname;
  DWORD                shi503_type;
  LMSTR                shi503_remark;
  DWORD                shi503_permissions;
  DWORD                shi503_max_uses;
  DWORD                shi503_current_uses;
  LMSTR                shi503_path;
  LMSTR                shi503_passwd;
  LMSTR                shi503_servername;
  DWORD                shi503_reserved;
  PSECURITY_DESCRIPTOR shi503_security_descriptor;
} SHARE_INFO_503, *PSHARE_INFO_503, *LPSHARE_INFO_503;