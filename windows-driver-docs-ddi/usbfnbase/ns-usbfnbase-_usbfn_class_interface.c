typedef struct _USBFN_CLASS_INTERFACE {
  UINT8                  InterfaceNumber;
  UINT8                  PipeCount;
  USBFN_PIPE_INFORMATION PipeArr[MAX_NUM_USBFN_PIPES];
} USBFN_CLASS_INTERFACE, *PUSBFN_CLASS_INTERFACE;