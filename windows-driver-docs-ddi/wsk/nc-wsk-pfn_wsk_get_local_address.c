PFN_WSK_GET_LOCAL_ADDRESS PfnWskGetLocalAddress;

NTSTATUS PfnWskGetLocalAddress(
  [in]      PWSK_SOCKET Socket,
  [out]     PSOCKADDR LocalAddress,
  [in, out] PIRP Irp
)
{...}