NTSTATUS AcxStreamCreate(
  WDFDEVICE              Device,
  ACXCIRCUIT             Circuit,
  PWDF_OBJECT_ATTRIBUTES Attributes,
  PACXSTREAM_INIT        *Config,
  ACXSTREAM              *Stream
);