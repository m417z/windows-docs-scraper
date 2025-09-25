NTSTATUS AcxPnpEventCreate(
  WDFDEVICE              Device,
  ACXOBJECT              Object,
  PWDF_OBJECT_ATTRIBUTES Attributes,
  PACX_PNPEVENT_CONFIG   Config,
  ACXPNPEVENT            *Event
);