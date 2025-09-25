PFN_WSK_CONTROL_SOCKET PfnWskControlSocket;

NTSTATUS PfnWskControlSocket(
  [in]            PWSK_SOCKET Socket,
  [in]            WSK_CONTROL_SOCKET_TYPE RequestType,
  [in]            ULONG ControlCode,
  [in]            ULONG Level,
  [in]            SIZE_T InputSize,
  [in, optional]  PVOID InputBuffer,
  [in]            SIZE_T OutputSize,
  [out, optional] PVOID OutputBuffer,
  [out, optional] SIZE_T *OutputSizeReturned,
  [in, out]       PIRP Irp
)
{...}