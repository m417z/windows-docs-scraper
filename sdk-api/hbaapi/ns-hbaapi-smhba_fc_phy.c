typedef struct SMHBA_FC_Phy {
  HBA_FCPHYSPEED PhySupportSpeed;
  HBA_FCPHYSPEED PhySpeed;
  HBA_FCPHYTYPE  PhyType;
  HBA_UINT32     MaxFrameSize;
} SMHBA_FC_PHY, *PSMHBA_FC_PHY;