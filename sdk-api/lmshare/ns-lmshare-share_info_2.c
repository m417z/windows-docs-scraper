typedef struct _SHARE_INFO_2 {
  LMSTR shi2_netname;
  DWORD shi2_type;
  LMSTR shi2_remark;
  DWORD shi2_permissions;
  DWORD shi2_max_uses;
  DWORD shi2_current_uses;
  LMSTR shi2_path;
  LMSTR shi2_passwd;
} SHARE_INFO_2, *PSHARE_INFO_2, *LPSHARE_INFO_2;