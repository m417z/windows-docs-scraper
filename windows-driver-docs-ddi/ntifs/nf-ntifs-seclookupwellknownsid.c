KSECDDDECLSPEC NTSTATUS SEC_ENTRY SecLookupWellKnownSid(
  [in]               WELL_KNOWN_SID_TYPE SidType,
  [out]              PSID                Sid,
  [in]               ULONG               SidBufferSize,
  [in_out, optional] PULONG              SidSize
);