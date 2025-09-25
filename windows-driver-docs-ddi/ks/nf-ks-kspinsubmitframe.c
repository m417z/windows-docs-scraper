KSDDKAPI NTSTATUS KsPinSubmitFrame(
  [in]           PKSPIN           Pin,
  [in, optional] PVOID            Data,
  [in, optional] ULONG            Size,
  [in, optional] PKSSTREAM_HEADER StreamHeader,
  [in, optional] PVOID            Context
);