typedef struct _MSiSCSI_RADIUSConfig {
  BOOLEAN          UseRADIUSForCHAP;
  ULONG            SharedSecretSizeInBytes;
  ISCSI_IP_Address RADIUSServer;
  ISCSI_IP_Address BackupRADIUSServer;
  ULONG            Reserved;
  UCHAR            SharedSecret[1];
} MSiSCSI_RADIUSConfig, *PMSiSCSI_RADIUSConfig;