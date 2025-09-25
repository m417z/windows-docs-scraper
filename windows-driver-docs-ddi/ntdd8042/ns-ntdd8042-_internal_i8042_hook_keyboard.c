typedef struct _INTERNAL_I8042_HOOK_KEYBOARD {
  OUT PVOID                                  Context;
  OUT PI8042_KEYBOARD_INITIALIZATION_ROUTINE InitializationRoutine;
  OUT PI8042_KEYBOARD_ISR                    IsrRoutine;
  IN PI8042_ISR_WRITE_PORT                   IsrWritePort;
  IN PI8042_QUEUE_PACKET                     QueueKeyboardPacket;
  IN PVOID                                   CallContext;
} INTERNAL_I8042_HOOK_KEYBOARD, *PINTERNAL_I8042_HOOK_KEYBOARD;