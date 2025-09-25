typedef struct _WDF_USB_CONTINUOUS_READER_CONFIG {
  ULONG                                 Size;
  size_t                                TransferLength;
  size_t                                HeaderLength;
  size_t                                TrailerLength;
  UCHAR                                 NumPendingReads;
  PWDF_OBJECT_ATTRIBUTES                BufferAttributes;
  PFN_WDF_USB_READER_COMPLETION_ROUTINE EvtUsbTargetPipeReadComplete;
  WDFCONTEXT                            EvtUsbTargetPipeReadCompleteContext;
  PFN_WDF_USB_READERS_FAILED            EvtUsbTargetPipeReadersFailed;
} WDF_USB_CONTINUOUS_READER_CONFIG, *PWDF_USB_CONTINUOUS_READER_CONFIG;