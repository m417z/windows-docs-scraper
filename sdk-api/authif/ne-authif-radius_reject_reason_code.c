typedef enum _RADIUS_REJECT_REASON_CODE {
  rrrcUndefined = 0,
  rrrcAccountUnknown = 1,
  rrrcAccountDisabled = 2,
  rrrcAccountExpired = 3,
  rrrcAuthenticationFailure = 4
} RADIUS_REJECT_REASON_CODE;