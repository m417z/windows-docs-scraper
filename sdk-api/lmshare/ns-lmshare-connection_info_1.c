typedef struct _CONNECTION_INFO_1 {
  DWORD coni1_id;
  DWORD coni1_type;
  DWORD coni1_num_opens;
  DWORD coni1_num_users;
  DWORD coni1_time;
  LMSTR coni1_username;
  LMSTR coni1_netname;
} CONNECTION_INFO_1, *PCONNECTION_INFO_1, *LPCONNECTION_INFO_1;