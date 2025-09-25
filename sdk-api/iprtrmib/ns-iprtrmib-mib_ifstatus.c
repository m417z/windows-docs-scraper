typedef struct _MIB_IFSTATUS {
  DWORD dwIfIndex;
  DWORD dwAdminStatus;
  DWORD dwOperationalStatus;
  BOOL  bMHbeatActive;
  BOOL  bMHbeatAlive;
} MIB_IFSTATUS, *PMIB_IFSTATUS;