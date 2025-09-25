typedef struct _IRB_REQ_ISOCH_DETACH_BUFFERS {
  HANDLE            hResource;
  ULONG             nNumberOfDescriptors;
  PISOCH_DESCRIPTOR pIsochDescriptor;
} IRB_REQ_ISOCH_DETACH_BUFFERS;