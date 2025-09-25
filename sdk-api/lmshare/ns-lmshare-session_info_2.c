typedef struct _SESSION_INFO_2 {
  LMSTR sesi2_cname;
  LMSTR sesi2_username;
  DWORD sesi2_num_opens;
  DWORD sesi2_time;
  DWORD sesi2_idle_time;
  DWORD sesi2_user_flags;
  LMSTR sesi2_cltype_name;
} SESSION_INFO_2, *PSESSION_INFO_2, *LPSESSION_INFO_2;