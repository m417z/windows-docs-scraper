typedef struct RILCALLLIST_V2 {
  DWORD          dwNumberOfCalls;
  RILCALLINFO_V2 rciCallInfo[1];
} RILCALLLIST_V2, *LPRILCALLLIST_V2;