typedef struct _CMSG_ENVELOPED_ENCODE_INFO {
  DWORD                       cbSize;
  HCRYPTPROV_LEGACY           hCryptProv;
  CRYPT_ALGORITHM_IDENTIFIER  ContentEncryptionAlgorithm;
  void                        *pvEncryptionAuxInfo;
  DWORD                       cRecipients;
  PCERT_INFO                  *rgpRecipients;
  PCMSG_RECIPIENT_ENCODE_INFO rgCmsRecipients;
  DWORD                       cCertEncoded;
  PCERT_BLOB                  rgCertEncoded;
  DWORD                       cCrlEncoded;
  PCRL_BLOB                   rgCrlEncoded;
  DWORD                       cAttrCertEncoded;
  PCERT_BLOB                  rgAttrCertEncoded;
  DWORD                       cUnprotectedAttr;
  PCRYPT_ATTRIBUTE            rgUnprotectedAttr;
} CMSG_ENVELOPED_ENCODE_INFO, *PCMSG_ENVELOPED_ENCODE_INFO;