KSDDKAPI NTSTATUS KsPinSubmitFrameMdl(
  [in]           PKSPIN           Pin,
  [in, optional] PMDL             Mdl,
  [in, optional] PKSSTREAM_HEADER StreamHeader,
  [in, optional] PVOID            Context
);