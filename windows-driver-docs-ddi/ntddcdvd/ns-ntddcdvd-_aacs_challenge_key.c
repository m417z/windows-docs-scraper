typedef struct _AACS_CHALLENGE_KEY {
  UCHAR EllipticCurvePoint[40];
  UCHAR Signature[40];
} AACS_CHALLENGE_KEY, *PAACS_CHALLENGE_KEY;