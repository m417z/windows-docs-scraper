NTSTATUS AcxPinAddEvents(
  [in]                     ACXPIN   Pin,
  [in, reads(EventsCount)] ACXEVENT *Events,
  [in]                     ULONG    EventsCount
);