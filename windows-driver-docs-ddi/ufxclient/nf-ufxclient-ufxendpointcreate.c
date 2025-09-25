NTSTATUS UfxEndpointCreate(
  [in]           UFXDEVICE              UfxDevice,
  [in, out]      PUFXENDPOINT_INIT      EndpointInit,
  [in, optional] PWDF_OBJECT_ATTRIBUTES Attributes,
  [in]           PWDF_IO_QUEUE_CONFIG   TransferQueueConfig,
  [in, optional] PWDF_OBJECT_ATTRIBUTES TransferQueueAttributes,
  [in]           PWDF_IO_QUEUE_CONFIG   CommandQueueConfig,
  [in, optional] PWDF_OBJECT_ATTRIBUTES CommandQueueAttributes,
  [out]          UFXENDPOINT            *UfxEndpoint
);