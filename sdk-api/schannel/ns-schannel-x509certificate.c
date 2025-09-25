typedef struct _X509Certificate {
  DWORD        Version;
  DWORD        SerialNumber[4];
  ALG_ID       SignatureAlgorithm;
  FILETIME     ValidFrom;
  FILETIME     ValidUntil;
  PSTR         pszIssuer;
  PSTR         pszSubject;
  PctPublicKey *pPublicKey;
} X509Certificate, *PX509Certificate;