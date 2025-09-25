NTSTATUS WdfInterruptCreate(
  [in]           WDFDEVICE              Device,
  [in]           PWDF_INTERRUPT_CONFIG  Configuration,
  [in, optional] PWDF_OBJECT_ATTRIBUTES Attributes,
  [out]          WDFINTERRUPT           *Interrupt
);