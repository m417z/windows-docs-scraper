typedef struct JOBOBJECT_NET_RATE_CONTROL_INFORMATION {
  DWORD64                           MaxBandwidth;
  JOB_OBJECT_NET_RATE_CONTROL_FLAGS ControlFlags;
  BYTE                              DscpTag;
} JOBOBJECT_NET_RATE_CONTROL_INFORMATION;