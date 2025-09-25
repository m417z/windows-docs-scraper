typedef struct _BRB_HEADER {
  LIST_ENTRY ListEntry;
  ULONG      Length;
  USHORT     Version;
  USHORT     Type;
  ULONG      BthportFlags;
  NTSTATUS   Status;
  BTHSTATUS  BtStatus;
  PVOID      Context[BTHPORT_CONTEXT_SIZE];
  PVOID      ClientContext[BTHPORT_CONTEXT_SIZE];
  ULONG      Reserved[BTHPORT_RESERVED_FIELD_SIZE];
} BRB_HEADER;