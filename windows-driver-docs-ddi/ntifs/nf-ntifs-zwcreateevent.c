NTSYSAPI NTSTATUS ZwCreateEvent(
  [out]          PHANDLE            EventHandle,
  [in]           ACCESS_MASK        DesiredAccess,
  [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
  [in]           EVENT_TYPE         EventType,
  [in]           BOOLEAN            InitialState
);