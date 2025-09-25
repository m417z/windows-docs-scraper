typedef struct _CRL_ISSUING_DIST_POINT {
  CRL_DIST_POINT_NAME DistPointName;
  BOOL                fOnlyContainsUserCerts;
  BOOL                fOnlyContainsCACerts;
  CRYPT_BIT_BLOB      OnlySomeReasonFlags;
  BOOL                fIndirectCRL;
} CRL_ISSUING_DIST_POINT, *PCRL_ISSUING_DIST_POINT;