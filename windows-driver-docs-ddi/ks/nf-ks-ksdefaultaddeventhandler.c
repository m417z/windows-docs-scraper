KSDDKAPI NTSTATUS KsDefaultAddEventHandler(
  [in]      PIRP           Irp,
  [in]      PKSEVENTDATA   EventData,
  [in, out] PKSEVENT_ENTRY EventEntry
);