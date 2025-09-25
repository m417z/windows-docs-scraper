typedef struct _CMSG_SIGNED_ENCODE_INFO {
  DWORD                    cbSize;
  DWORD                    cSigners;
  PCMSG_SIGNER_ENCODE_INFO rgSigners;
  DWORD                    cCertEncoded;
  PCERT_BLOB               rgCertEncoded;
  DWORD                    cCrlEncoded;
  PCRL_BLOB                rgCrlEncoded;
  DWORD                    cAttrCertEncoded;
  PCERT_BLOB               rgAttrCertEncoded;
} CMSG_SIGNED_ENCODE_INFO, *PCMSG_SIGNED_ENCODE_INFO;