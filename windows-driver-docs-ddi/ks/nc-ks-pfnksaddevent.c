PFNKSADDEVENT Pfnksaddevent;

NTSTATUS Pfnksaddevent(
  [in] PIRP Irp,
  [in] PKSEVENTDATA EventData,
  [in] _KSEVENT_ENTRY *EventEntry
)
{...}