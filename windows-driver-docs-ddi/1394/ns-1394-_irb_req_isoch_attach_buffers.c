typedef struct _IRB_REQ_ISOCH_ATTACH_BUFFERS {
  HANDLE            hResource;
  ULONG             nNumberOfDescriptors;
  PISOCH_DESCRIPTOR pIsochDescriptor;
} IRB_REQ_ISOCH_ATTACH_BUFFERS;