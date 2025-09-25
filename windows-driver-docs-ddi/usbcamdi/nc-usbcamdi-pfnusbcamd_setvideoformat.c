PFNUSBCAMD_SetVideoFormat PfnusbcamdSetvideoformat;

NTSTATUS PfnusbcamdSetvideoformat(
  [in] PVOID DeviceContext,
  [in] PHW_STREAM_REQUEST_BLOCK pSrb
)
{...}