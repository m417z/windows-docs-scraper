PFN_WSK_GET_NAME_INFO PfnWskGetNameInfo;

NTSTATUS PfnWskGetNameInfo(
  [in]            PWSK_CLIENT Client,
  [in]            PSOCKADDR SockAddr,
  [in]            ULONG SockAddrLength,
  [out, optional] PUNICODE_STRING NodeName,
  [out, optional] PUNICODE_STRING ServiceName,
  [in]            ULONG Flags,
  [in, optional]  PEPROCESS OwningProcess,
  [in, optional]  PETHREAD OwningThread,
  [in, out]       PIRP Irp
)
{...}