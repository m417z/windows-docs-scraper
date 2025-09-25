NTSTATUS WdfRequestImpersonate(
  [in]           WDFREQUEST                   Request,
  [in]           SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
  [in]           PFN_WDF_REQUEST_IMPERSONATE  EvtRequestImpersonate,
  [in, optional] PVOID                        Context
);