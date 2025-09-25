typedef struct _SHARE_INFO_502 {
  LMSTR                shi502_netname;
  DWORD                shi502_type;
  LMSTR                shi502_remark;
  DWORD                shi502_permissions;
  DWORD                shi502_max_uses;
  DWORD                shi502_current_uses;
  LMSTR                shi502_path;
  LMSTR                shi502_passwd;
  DWORD                shi502_reserved;
  PSECURITY_DESCRIPTOR shi502_security_descriptor;
} SHARE_INFO_502, *PSHARE_INFO_502, *LPSHARE_INFO_502;