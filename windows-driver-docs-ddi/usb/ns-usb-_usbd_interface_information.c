typedef struct _USBD_INTERFACE_INFORMATION {
  USHORT                Length;
  UCHAR                 InterfaceNumber;
  UCHAR                 AlternateSetting;
  UCHAR                 Class;
  UCHAR                 SubClass;
  UCHAR                 Protocol;
  UCHAR                 Reserved;
  USBD_INTERFACE_HANDLE InterfaceHandle;
  ULONG                 NumberOfPipes;
  USBD_PIPE_INFORMATION Pipes[1];
} USBD_INTERFACE_INFORMATION, *PUSBD_INTERFACE_INFORMATION;