typedef struct _STAT_SERVER_0 {
  DWORD sts0_start;
  DWORD sts0_fopens;
  DWORD sts0_devopens;
  DWORD sts0_jobsqueued;
  DWORD sts0_sopens;
  DWORD sts0_stimedout;
  DWORD sts0_serrorout;
  DWORD sts0_pwerrors;
  DWORD sts0_permerrors;
  DWORD sts0_syserrors;
  DWORD sts0_bytessent_low;
  DWORD sts0_bytessent_high;
  DWORD sts0_bytesrcvd_low;
  DWORD sts0_bytesrcvd_high;
  DWORD sts0_avresponse;
  DWORD sts0_reqbufneed;
  DWORD sts0_bigbufneed;
} STAT_SERVER_0, *PSTAT_SERVER_0, *LPSTAT_SERVER_0;