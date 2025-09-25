NTSTATUS SerCx2SystemDmaReceiveCreate(
  [in]           WDFDEVICE                         Device,
  [in]           PSERCX2_SYSTEM_DMA_RECEIVE_CONFIG SystemDmaReceiveConfig,
  [in, optional] PWDF_OBJECT_ATTRIBUTES            Attributes,
  [out]          SERCX2SYSTEMDMARECEIVE            *SystemDmaReceive
);