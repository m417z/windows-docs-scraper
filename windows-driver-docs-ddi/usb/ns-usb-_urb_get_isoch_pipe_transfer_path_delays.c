struct _URB_GET_ISOCH_PIPE_TRANSFER_PATH_DELAYS {
  struct _URB_HEADER Hdr;
  USBD_PIPE_HANDLE   PipeHandle;
  ULONG              MaximumSendPathDelayInMilliSeconds;
  ULONG              MaximumCompletionPathDelayInMilliSeconds;
};