NTSTATUS AcxPinAddJacks(
  [in]                   ACXPIN  Pin,
  [in, reads(jackCount)] ACXJACK *Jacks,
  [in]                   ULONG   jackCount
);