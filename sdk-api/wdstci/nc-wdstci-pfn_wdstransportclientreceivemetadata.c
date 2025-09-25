PFN_WdsTransportClientReceiveMetadata PfnWdstransportclientreceivemetadata;

VOID PfnWdstransportclientreceivemetadata(
  [in] HANDLE hSessionKey,
  [in] PVOID pCallerData,
  [in] PVOID pMetadata,
  [in] ULONG ulSize
)
{...}