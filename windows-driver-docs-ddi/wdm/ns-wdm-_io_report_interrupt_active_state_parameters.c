typedef struct _IO_REPORT_INTERRUPT_ACTIVE_STATE_PARAMETERS {
  ULONG Version;
  union {
    PVOID                      Generic;
    PKINTERRUPT                InterruptObject;
    PIO_INTERRUPT_MESSAGE_INFO InterruptMessageTable;
  } ConnectionContext;
} IO_REPORT_INTERRUPT_ACTIVE_STATE_PARAMETERS, *PIO_REPORT_INTERRUPT_ACTIVE_STATE_PARAMETERS;