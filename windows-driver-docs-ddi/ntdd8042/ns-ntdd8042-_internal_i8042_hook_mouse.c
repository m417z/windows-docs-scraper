typedef struct _INTERNAL_I8042_HOOK_MOUSE {
  OUT PVOID                Context;
  OUT PI8042_MOUSE_ISR     IsrRoutine;
  IN PI8042_ISR_WRITE_PORT IsrWritePort;
  IN PI8042_QUEUE_PACKET   QueueMousePacket;
  IN PVOID                 CallContext;
} INTERNAL_I8042_HOOK_MOUSE, *PINTERNAL_I8042_HOOK_MOUSE;