struct IDARG_IN_OPM_GET_CERTIFICATE {
  OPM_VIDEO_OUTPUT_SEMANTICS CertificateType;
  UINT                       CertificateBufferSizeInBytes;
  PVOID                      pCertificate;
};