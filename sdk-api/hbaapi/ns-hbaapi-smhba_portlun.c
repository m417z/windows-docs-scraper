typedef struct SMHBA_PORTLUN {
  HBA_WWN     PortWWN;
  HBA_WWN     domainPortWWN;
  HBA_SCSILUN TargetLun;
} SMHBA_PORTLUN, *PSMHBA_PORTLUN;