NTSTATUS FwpmFilterAdd0(
  [in]            HANDLE               engineHandle,
  [in]            const FWPM_FILTER0   *filter,
  [in, optional]  PSECURITY_DESCRIPTOR sd,
  [out, optional] UINT64               *id
);