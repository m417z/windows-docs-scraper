typedef struct _USB_NODE_CONNECTION_INFORMATION_EX {
  ULONG                 ConnectionIndex;
  USB_DEVICE_DESCRIPTOR DeviceDescriptor;
  UCHAR                 CurrentConfigurationValue;
  UCHAR                 Speed;
  BOOLEAN               DeviceIsHub;
  USHORT                DeviceAddress;
  ULONG                 NumberOfOpenPipes;
  USB_CONNECTION_STATUS ConnectionStatus;
  USB_PIPE_INFO         PipeList[0];
} USB_NODE_CONNECTION_INFORMATION_EX, *PUSB_NODE_CONNECTION_INFORMATION_EX;