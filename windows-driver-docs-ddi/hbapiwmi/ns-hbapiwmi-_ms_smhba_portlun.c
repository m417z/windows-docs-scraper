typedef struct _MS_SMHBA_PORTLUN {
  UCHAR     PortWWN[8];
  UCHAR     domainPortWWN[8];
  ULONGLONG TargetLun;
} MS_SMHBA_PORTLUN, *PMS_SMHBA_PORTLUN;