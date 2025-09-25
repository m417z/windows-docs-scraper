typedef struct _CERT_BIOMETRIC_DATA {
  DWORD           dwTypeOfBiometricDataChoice;
  union {
    DWORD dwPredefined;
    LPSTR pszObjId;
  } DUMMYUNIONNAME;
  CERT_HASHED_URL HashedUrl;
} CERT_BIOMETRIC_DATA, *PCERT_BIOMETRIC_DATA;