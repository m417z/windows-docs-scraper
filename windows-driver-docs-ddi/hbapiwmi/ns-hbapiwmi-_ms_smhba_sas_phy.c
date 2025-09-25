typedef struct _MS_SMHBA_SAS_PHY {
  UCHAR PhyIdentifier;
  ULONG NegotiatedLinkRate;
  ULONG ProgrammedMinLinkRate;
  ULONG HardwareMinLinkRate;
  ULONG ProgrammedMaxLinkRate;
  ULONG HardwareMaxLinkRate;
  UCHAR domainPortWWN[8];
} MS_SMHBA_SAS_PHY, *PMS_SMHBA_SAS_PHY;