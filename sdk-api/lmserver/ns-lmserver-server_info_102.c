typedef struct _SERVER_INFO_102 {
  DWORD sv102_platform_id;
  LMSTR sv102_name;
  DWORD sv102_version_major;
  DWORD sv102_version_minor;
  DWORD sv102_type;
  LMSTR sv102_comment;
  DWORD sv102_users;
  LONG  sv102_disc;
  BOOL  sv102_hidden;
  DWORD sv102_announce;
  DWORD sv102_anndelta;
  DWORD sv102_licenses;
  LMSTR sv102_userpath;
} SERVER_INFO_102, *PSERVER_INFO_102, *LPSERVER_INFO_102;