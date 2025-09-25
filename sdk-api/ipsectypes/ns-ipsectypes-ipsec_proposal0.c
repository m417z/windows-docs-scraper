typedef struct IPSEC_PROPOSAL0_ {
  IPSEC_SA_LIFETIME0  lifetime;
  UINT32              numSaTransforms;
  IPSEC_SA_TRANSFORM0 *saTransforms;
  IPSEC_PFS_GROUP     pfsGroup;
} IPSEC_PROPOSAL0;