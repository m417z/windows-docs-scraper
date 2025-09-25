typedef struct _MSiSCSI_BootInformation {
  UCHAR NodeName[223];
  ULONG SharedSecretLength;
  UCHAR SharedSecret[255];
} MSiSCSI_BootInformation, *PMSiSCSI_BootInformation;