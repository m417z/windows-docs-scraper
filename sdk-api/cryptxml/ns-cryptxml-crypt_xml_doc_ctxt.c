typedef struct _CRYPT_XML_DOC_CTXT {
  ULONG                            cbSize;
  HCRYPTXML                        hDocCtxt;
  CRYPT_XML_TRANSFORM_CHAIN_CONFIG *pTransformsConfig;
  ULONG                            cSignature;
  PCRYPT_XML_SIGNATURE             *rgpSignature;
} CRYPT_XML_DOC_CTXT, *PCRYPT_XML_DOC_CTXT;