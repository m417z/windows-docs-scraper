NTSTATUS WdfIoTargetCreate(
  [in]           WDFDEVICE              Device,
  [in, optional] PWDF_OBJECT_ATTRIBUTES IoTargetAttributes,
  [out]          WDFIOTARGET            *IoTarget
);