typedef struct RILCALLLIST_V1 {
  DWORD          dwNumberOfCalls;
  RILCALLINFO_V1 rciCallInfo[1];
} RILCALLLIST_V1, *LPRILCALLLIST_V1;