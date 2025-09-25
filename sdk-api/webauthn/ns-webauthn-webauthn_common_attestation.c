typedef struct _WEBAUTHN_COMMON_ATTESTATION {
  DWORD         dwVersion;
  PCWSTR        pwszAlg;
  LONG          lAlg;
  DWORD         cbSignature;
  PBYTE         pbSignature;
  DWORD         cX5c;
  PWEBAUTHN_X5C pX5c;
  PCWSTR        pwszVer;
  DWORD         cbCertInfo;
  PBYTE         pbCertInfo;
  DWORD         cbPubArea;
  PBYTE         pbPubArea;
} WEBAUTHN_COMMON_ATTESTATION, *PWEBAUTHN_COMMON_ATTESTATION;