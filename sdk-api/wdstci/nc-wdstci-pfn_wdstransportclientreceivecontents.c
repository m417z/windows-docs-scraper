PFN_WdsTransportClientReceiveContents PfnWdstransportclientreceivecontents;

VOID PfnWdstransportclientreceivecontents(
  [in] HANDLE hSessionKey,
  [in] PVOID pCallerData,
       PVOID pContents,
  [in] ULONG ulSize,
       PULARGE_INTEGER pullContentOffset
)
{...}