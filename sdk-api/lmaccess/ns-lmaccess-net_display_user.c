typedef struct _NET_DISPLAY_USER {
  LPWSTR usri1_name;
  LPWSTR usri1_comment;
  DWORD  usri1_flags;
  LPWSTR usri1_full_name;
  DWORD  usri1_user_id;
  DWORD  usri1_next_index;
} NET_DISPLAY_USER, *PNET_DISPLAY_USER;