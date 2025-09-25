typedef struct _TRUSTEE_W {
  struct _TRUSTEE_W          *pMultipleTrustee;
  MULTIPLE_TRUSTEE_OPERATION MultipleTrusteeOperation;
  TRUSTEE_FORM               TrusteeForm;
  TRUSTEE_TYPE               TrusteeType;
  union {
    LPWSTR             ptstrName;
    SID                *pSid;
    OBJECTS_AND_SID    *pObjectsAndSid;
    OBJECTS_AND_NAME_W *pObjectsAndName;
  };
  LPWCH                      ptstrName;
} TRUSTEE_W, *PTRUSTEE_W, TRUSTEEW, *PTRUSTEEW;