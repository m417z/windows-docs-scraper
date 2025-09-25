EVT_IDD_CX_MONITOR_OPM_GET_CERTIFICATE_SIZE EvtIddCxMonitorOpmGetCertificateSize;

NTSTATUS EvtIddCxMonitorOpmGetCertificateSize(
  [in]  IDDCX_ADAPTER AdapterObject,
  [in]  const IDARG_IN_OPM_GET_CERTIFICATE_SIZE *pInArgs,
  [out] IDARG_OUT_OPM_GET_CERTIFICATE_SIZE *pOutArgs
)
{...}