typedef struct _USBFN_INTERFACE_ATTACH {
  INTERFACE                         InterfaceHeader;
  PFN_USBFN_GET_ATTACH_ACTION       GetAttachAction;
  PFN_USBFN_GET_ATTACH_ACTION_ABORT GetAttachActionAbortOperation;
  PFN_USBFN_SET_DEVICE_STATE        SetDeviceState;
} USBFN_INTERFACE_ATTACH, *PUSBFN_INTERFACE_ATTACH;