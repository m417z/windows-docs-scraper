DXGKDDI_OPM_GET_CERTIFICATE_SIZE DxgkddiOpmGetCertificateSize;

NTSTATUS DxgkddiOpmGetCertificateSize(
  [in]  PVOID MiniportDeviceContext,
  [in]  DXGKMDT_CERTIFICATE_TYPE CertificateType,
  [out] PULONG CertificateSize
)
{...}