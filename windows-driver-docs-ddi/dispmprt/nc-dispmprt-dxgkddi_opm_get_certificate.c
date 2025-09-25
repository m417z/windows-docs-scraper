DXGKDDI_OPM_GET_CERTIFICATE DxgkddiOpmGetCertificate;

NTSTATUS DxgkddiOpmGetCertificate(
  [in]  PVOID MiniportDeviceContext,
  [in]  DXGKMDT_CERTIFICATE_TYPE CertificateType,
  [in]  ULONG CertificateSize,
  [out] PVOID CertificateBuffer
)
{...}