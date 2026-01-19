VOID WriteNtStatusToMode(
  volatile NTSTATUS *Destination,
  NTSTATUS          Value,
  KPROCESSOR_MODE   Mode
);