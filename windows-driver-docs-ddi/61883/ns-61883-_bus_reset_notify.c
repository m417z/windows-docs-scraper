typedef struct _BUS_RESET_NOTIFY {
  IN ULONG              Flags;
  IN PBUS_RESET_ROUTINE pfnNotify;
  IN PVOID              Context;
} BUS_RESET_NOTIFY, *PBUS_RESET_NOTIFY;