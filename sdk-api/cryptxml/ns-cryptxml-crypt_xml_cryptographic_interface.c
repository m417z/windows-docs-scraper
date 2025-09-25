typedef struct _CRYPT_XML_CRYPTOGRAPHIC_INTERFACE {
  ULONG                       cbSize;
  CryptXmlDllEncodeAlgorithm  fpCryptXmlEncodeAlgorithm;
  CryptXmlDllCreateDigest     fpCryptXmlCreateDigest;
  CryptXmlDllDigestData       fpCryptXmlDigestData;
  CryptXmlDllFinalizeDigest   fpCryptXmlFinalizeDigest;
  CryptXmlDllCloseDigest      fpCryptXmlCloseDigest;
  CryptXmlDllSignData         fpCryptXmlSignData;
  CryptXmlDllVerifySignature  fpCryptXmlVerifySignature;
  CryptXmlDllGetAlgorithmInfo fpCryptXmlGetAlgorithmInfo;
} CRYPT_XML_CRYPTOGRAPHIC_INTERFACE, *PCRYPT_XML_CRYPTO_PROVIDER, *PCRYPT_XML_CRYPTOGRAPHIC_INTERFACE;