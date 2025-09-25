NTSTATUS LsaGetAppliedCAPIDs(
  [in, optional] PLSA_UNICODE_STRING SystemName,
  [out]          PSID                **CAPIDs,
  [out]          PULONG              CAPIDCount
);