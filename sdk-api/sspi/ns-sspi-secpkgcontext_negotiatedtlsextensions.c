typedef struct _SecPkgContext_NegotiatedTlsExtensions {
  unsigned long  ExtensionsCount;
  unsigned short *Extensions;
} SecPkgContext_NegotiatedTlsExtensions, *PSecPkgContext_NegotiatedTlsExtensions;