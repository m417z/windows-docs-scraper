typedef enum X509SCEPDisposition {
  SCEPDispositionUnknown = -1,
  SCEPDispositionSuccess = 0,
  SCEPDispositionFailure = 2,
  SCEPDispositionPending = 3,
  SCEPDispositionPendingChallenge = 11
} ;