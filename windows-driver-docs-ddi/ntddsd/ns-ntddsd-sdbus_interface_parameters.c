typedef struct _SDBUS_INTERFACE_PARAMETERS {
  USHORT                  Size;
  USHORT                  SdioFlags;
  PDEVICE_OBJECT          TargetObject;
  BOOLEAN                 DeviceGeneratesInterrupts;
  BOOLEAN                 CallbackAtDpcLevel;
  PSDBUS_CALLBACK_ROUTINE CallbackRoutine;
  PVOID                   CallbackRoutineContext;
} SDBUS_INTERFACE_PARAMETERS, *PSDBUS_INTERFACE_PARAMETERS;