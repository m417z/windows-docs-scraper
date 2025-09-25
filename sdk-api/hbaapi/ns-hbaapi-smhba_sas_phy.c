typedef struct SMHBA_SAS_Phy {
  HBA_UINT8       PhyIdentifier;
  HBA_SASPHYSPEED NegotiatedLinkRate;
  HBA_SASPHYSPEED ProgrammedMinLinkRate;
  HBA_SASPHYSPEED HardwareMinLinkRate;
  HBA_SASPHYSPEED ProgrammedMaxLinkRate;
  HBA_SASPHYSPEED HardwareMaxLinkRate;
  HBA_WWN         domainPortWWN;
} SMHBA_SAS_PHY, *PSMHBA_SAS_PHY;