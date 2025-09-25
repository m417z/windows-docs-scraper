PFN_WSK_GET_REMOTE_ADDRESS PfnWskGetRemoteAddress;

NTSTATUS PfnWskGetRemoteAddress(
  [in]      PWSK_SOCKET Socket,
  [out]     PSOCKADDR RemoteAddress,
  [in, out] PIRP Irp
)
{...}