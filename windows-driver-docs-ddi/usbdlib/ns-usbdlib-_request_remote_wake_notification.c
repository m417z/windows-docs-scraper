typedef struct _REQUEST_REMOTE_WAKE_NOTIFICATION {
  USHORT               Version;
  USHORT               Size;
  USBD_FUNCTION_HANDLE UsbdFunctionHandle;
  ULONG                Interface;
} REQUEST_REMOTE_WAKE_NOTIFICATION, *PREQUEST_REMOTE_WAKE_NOTIFICATION;