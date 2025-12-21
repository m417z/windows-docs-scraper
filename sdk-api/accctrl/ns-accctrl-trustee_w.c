typedef struct _TRUSTEE_W {
  struct _TRUSTEE_W          *pMultipleTrustee;
  MULTIPLE_TRUSTEE_OPERATION MultipleTrusteeOperation;
  TRUSTEE_FORM               TrusteeForm;
  TRUSTEE_TYPE               TrusteeType;
  LPWCH                      ptstrName;
} TRUSTEE_W, *PTRUSTEE_W, TRUSTEEW, *PTRUSTEEW;