typedef struct _USB_PIPE_INFO {
  USB_ENDPOINT_DESCRIPTOR EndpointDescriptor;
  ULONG                   ScheduleOffset;
} USB_PIPE_INFO, *PUSB_PIPE_INFO;