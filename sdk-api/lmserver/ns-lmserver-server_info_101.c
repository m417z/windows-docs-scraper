typedef struct _SERVER_INFO_101 {
  DWORD sv101_platform_id;
  LMSTR sv101_name;
  DWORD sv101_version_major;
  DWORD sv101_version_minor;
  DWORD sv101_type;
  LMSTR sv101_comment;
} SERVER_INFO_101, *PSERVER_INFO_101, *LPSERVER_INFO_101;