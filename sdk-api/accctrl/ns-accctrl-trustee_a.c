typedef struct _TRUSTEE_A {
  struct _TRUSTEE_A          *pMultipleTrustee;
  MULTIPLE_TRUSTEE_OPERATION MultipleTrusteeOperation;
  TRUSTEE_FORM               TrusteeForm;
  TRUSTEE_TYPE               TrusteeType;
  union {
    LPSTR              ptstrName;
    SID                *pSid;
    OBJECTS_AND_SID    *pObjectsAndSid;
    OBJECTS_AND_NAME_A *pObjectsAndName;
  };
  LPCH                       ptstrName;
} TRUSTEE_A, *PTRUSTEE_A, TRUSTEEA, *PTRUSTEEA;