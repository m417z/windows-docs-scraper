typedef struct _ISCSI_LoginOptions {
  ULONG InformationSpecified;
  ULONG HeaderDigest;
  ULONG DataDigest;
  ULONG MaximumConnections;
  ULONG DefaultTime2Wait;
  ULONG DefaultTime2Retain;
  ULONG LoginFlags;
  ULONG AuthType;
} ISCSI_LoginOptions, *PISCSI_LoginOptions;