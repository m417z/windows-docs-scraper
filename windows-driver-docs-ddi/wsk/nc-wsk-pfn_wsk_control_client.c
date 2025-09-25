PFN_WSK_CONTROL_CLIENT PfnWskControlClient;

NTSTATUS PfnWskControlClient(
  [in]            PWSK_CLIENT Client,
  [in]            ULONG ControlCode,
  [in]            SIZE_T InputSize,
  [in, optional]  PVOID InputBuffer,
  [in]            SIZE_T OutputSize,
  [out, optional] PVOID OutputBuffer,
  [out, optional] SIZE_T *OutputSizeReturned,
  [in, out]       PIRP Irp
)
{...}