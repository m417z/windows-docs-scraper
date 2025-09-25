typedef struct _BDCB_IMAGE_INFORMATION {
  BDCB_CLASSIFICATION Classification;
  ULONG               ImageFlags;
  UNICODE_STRING      ImageName;
  UNICODE_STRING      RegistryPath;
  UNICODE_STRING      CertificatePublisher;
  UNICODE_STRING      CertificateIssuer;
  PVOID               ImageHash;
  PVOID               CertificateThumbprint;
  ULONG               ImageHashAlgorithm;
  ULONG               ThumbprintHashAlgorithm;
  ULONG               ImageHashLength;
  ULONG               CertificateThumbprintLength;
} BDCB_IMAGE_INFORMATION, *PBDCB_IMAGE_INFORMATION;