PFN_WdsTransportClientSessionStart PfnWdstransportclientsessionstart;

VOID PfnWdstransportclientsessionstart(
  [in] HANDLE hSessionKey,
  [in] PVOID pCallerData,
       PULARGE_INTEGER ullFileSize
)
{...}