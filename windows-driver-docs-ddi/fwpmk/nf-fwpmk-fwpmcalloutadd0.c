NTSTATUS FwpmCalloutAdd0(
  [in]            HANDLE               engineHandle,
  [in]            const FWPM_CALLOUT0  *callout,
  [in, optional]  PSECURITY_DESCRIPTOR sd,
  [out, optional] UINT32               *id
);