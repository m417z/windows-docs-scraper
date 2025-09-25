PFN_WdsTransportClientSessionComplete PfnWdstransportclientsessioncomplete;

VOID PfnWdstransportclientsessioncomplete(
  [in] HANDLE hSessionKey,
  [in] PVOID pCallerData,
  [in] DWORD dwError
)
{...}