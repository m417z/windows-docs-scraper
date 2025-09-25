typedef struct _DOT11_PHY_TYPE_INFO {
  union {
    DOT11_PHY_TYPE dot11PhyType;
    ULONG          uPhyId;
  };
  BOOLEAN             bUseParameters;
  ULONG               uProbeDelay;
  ULONG               uMinChannelTime;
  ULONG               uMaxChannelTime;
  CH_DESCRIPTION_TYPE ChDescriptionType;
  ULONG               uChannelListSize;
  UCHAR               ucChannelListBuffer[1];
} DOT11_PHY_TYPE_INFO, *PDOT11_PHY_TYPE_INFO;