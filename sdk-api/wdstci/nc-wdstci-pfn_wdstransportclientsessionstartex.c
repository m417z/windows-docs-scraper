PFN_WdsTransportClientSessionStartEx PfnWdstransportclientsessionstartex;

VOID PfnWdstransportclientsessionstartex(
  [in] HANDLE hSessionKey,
  [in] PVOID pCallerData,
  [in] PTRANSPORTCLIENT_SESSION_INFO Info
)
{...}