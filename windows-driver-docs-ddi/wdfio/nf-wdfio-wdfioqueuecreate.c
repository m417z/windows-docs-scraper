NTSTATUS WdfIoQueueCreate(
  [in]            WDFDEVICE              Device,
  [in]            PWDF_IO_QUEUE_CONFIG   Config,
  [in, optional]  PWDF_OBJECT_ATTRIBUTES QueueAttributes,
  [out, optional] WDFQUEUE               *Queue
);