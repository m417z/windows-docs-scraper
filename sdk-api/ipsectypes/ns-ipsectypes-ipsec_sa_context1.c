typedef struct IPSEC_SA_CONTEXT1_ {
  UINT64            saContextId;
  IPSEC_SA_DETAILS1 *inboundSa;
  IPSEC_SA_DETAILS1 *outboundSa;
} IPSEC_SA_CONTEXT1;