typedef enum _COPP_CGMSA_Protection_Level {
  COPP_CGMSA_Disabled = 0,
  COPP_CGMSA_LevelMin,
  COPP_CGMSA_CopyFreely = 1,
  COPP_CGMSA_CopyNoMore = 2,
  COPP_CGMSA_CopyOneGeneration = 3,
  COPP_CGMSA_CopyNever = 4,
  COPP_CGMSA_RedistributionControlRequired = 0x08,
  COPP_CGMSA_LevelMax,
  COPP_CGMSA_ForceDWORD = 0x7fffffff
} COPP_CGMSA_Protection_Level;