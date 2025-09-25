typedef struct _SESSION_INFO_1 {
  LMSTR sesi1_cname;
  LMSTR sesi1_username;
  DWORD sesi1_num_opens;
  DWORD sesi1_time;
  DWORD sesi1_idle_time;
  DWORD sesi1_user_flags;
} SESSION_INFO_1, *PSESSION_INFO_1, *LPSESSION_INFO_1;