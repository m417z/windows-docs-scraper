typedef struct _CMP_NOTIFY_INFO {
  HANDLE hPlug;
  AV_PCR Pcr;
  PVOID  Context;
} CMP_NOTIFY_INFO, *PCMP_NOTIFY_INFO;