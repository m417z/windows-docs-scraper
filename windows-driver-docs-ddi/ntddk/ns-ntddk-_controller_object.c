typedef struct _CONTROLLER_OBJECT {
  CSHORT        Type;
  CSHORT        Size;
  PVOID         ControllerExtension;
  KDEVICE_QUEUE DeviceWaitQueue;
  ULONG         Spare1;
  LARGE_INTEGER Spare2;
} CONTROLLER_OBJECT, *PCONTROLLER_OBJECT;