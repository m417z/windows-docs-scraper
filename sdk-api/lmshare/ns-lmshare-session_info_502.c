typedef struct _SESSION_INFO_502 {
  LMSTR sesi502_cname;
  LMSTR sesi502_username;
  DWORD sesi502_num_opens;
  DWORD sesi502_time;
  DWORD sesi502_idle_time;
  DWORD sesi502_user_flags;
  LMSTR sesi502_cltype_name;
  LMSTR sesi502_transport;
} SESSION_INFO_502, *PSESSION_INFO_502, *LPSESSION_INFO_502;