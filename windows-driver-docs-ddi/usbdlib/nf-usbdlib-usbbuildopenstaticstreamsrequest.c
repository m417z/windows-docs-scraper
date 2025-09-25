VOID UsbBuildOpenStaticStreamsRequest(
  [in, out] PURB                     Urb,
  [in]      USBD_PIPE_HANDLE         PipeHandle,
  [in]      USHORT                   NumberOfStreams,
  [in]      PUSBD_STREAM_INFORMATION StreamInfoArray
);