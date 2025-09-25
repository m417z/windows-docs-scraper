PFN_WSK_GET_ADDRESS_INFO PfnWskGetAddressInfo;

NTSTATUS PfnWskGetAddressInfo(
  [in]           PWSK_CLIENT Client,
  [in, optional] PUNICODE_STRING NodeName,
  [in, optional] PUNICODE_STRING ServiceName,
  [in, optional] ULONG NameSpace,
  [in, optional] GUID *Provider,
  [in, optional] PADDRINFOEXW Hints,
  [out]          PADDRINFOEXW *Result,
  [in, optional] PEPROCESS OwningProcess,
  [in, optional] PETHREAD OwningThread,
  [in, out]      PIRP Irp
)
{...}