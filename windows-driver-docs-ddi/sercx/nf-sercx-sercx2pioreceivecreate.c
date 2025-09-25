NTSTATUS SerCx2PioReceiveCreate(
  [in]           WDFDEVICE                  Device,
  [in]           PSERCX2_PIO_RECEIVE_CONFIG PioReceiveConfig,
  [in, optional] PWDF_OBJECT_ATTRIBUTES     Attributes,
  [out]          SERCX2PIORECEIVE           *PioReceive
);