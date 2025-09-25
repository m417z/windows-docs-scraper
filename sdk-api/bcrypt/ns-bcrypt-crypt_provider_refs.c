typedef struct _CRYPT_PROVIDER_REFS {
  ULONG               cProviders;
  PCRYPT_PROVIDER_REF *rgpProviders;
} CRYPT_PROVIDER_REFS, *PCRYPT_PROVIDER_REFS;