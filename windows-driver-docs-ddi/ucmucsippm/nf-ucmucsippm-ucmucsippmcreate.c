NTSTATUS UcmUcsiPpmCreate(
  [in]  WDFDEVICE              WdfDevice,
  [in]  PUCMUCSI_PPM_CONFIG    Config,
  [in]  PWDF_OBJECT_ATTRIBUTES Attributes,
  [out] UCMUCSIPPM             *PPMObject
);