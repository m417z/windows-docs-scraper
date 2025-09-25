typedef struct _IO_DISCONNECT_INTERRUPT_PARAMETERS {
  ULONG Version;
  union {
    PVOID                      Generic;
    PKINTERRUPT                InterruptObject;
    PIO_INTERRUPT_MESSAGE_INFO InterruptMessageTable;
  } ConnectionContext;
} IO_DISCONNECT_INTERRUPT_PARAMETERS, *PIO_DISCONNECT_INTERRUPT_PARAMETERS;