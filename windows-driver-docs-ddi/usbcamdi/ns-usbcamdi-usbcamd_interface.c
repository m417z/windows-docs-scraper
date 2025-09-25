typedef struct {
  INTERFACE                      Interface;
  PFNUSBCAMD_WaitOnDeviceEvent   USBCAMD_WaitOnDeviceEvent;
  PFNUSBCAMD_BulkReadWrite       USBCAMD_BulkReadWrite;
  PFNUSBCAMD_SetVideoFormat      USBCAMD_SetVideoFormat;
  PFNUSBCAMD_SetIsoPipeState     USBCAMD_SetIsoPipeState;
  PFNUSBCAMD_CancelBulkReadWrite USBCAMD_CancelBulkReadWrite;
} USBCAMD_INTERFACE, *PUSBCAMD_INTERFACE;