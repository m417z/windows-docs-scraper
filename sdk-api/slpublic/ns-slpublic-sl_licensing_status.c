typedef struct _tagSL_LICENSING_STATUS {
  SLID              SkuId;
  SLLICENSINGSTATUS eStatus;
  DWORD             dwGraceTime;
  DWORD             dwTotalGraceDays;
  HRESULT           hrReason;
  UINT64            qwValidityExpiration;
} SL_LICENSING_STATUS;