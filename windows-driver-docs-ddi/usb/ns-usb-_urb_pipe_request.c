struct _URB_PIPE_REQUEST {
  struct _URB_HEADER Hdr;
  USBD_PIPE_HANDLE   PipeHandle;
  ULONG              Reserved;
};