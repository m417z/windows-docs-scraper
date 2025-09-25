NTSYSAPI ULONGLONG RtlIoDecodeMemIoResource(
  [in]            PIO_RESOURCE_DESCRIPTOR Descriptor,
  [out, optional] PULONGLONG              Alignment,
  [out, optional] PULONGLONG              MinimumAddress,
  [out, optional] PULONGLONG              MaximumAddress
);