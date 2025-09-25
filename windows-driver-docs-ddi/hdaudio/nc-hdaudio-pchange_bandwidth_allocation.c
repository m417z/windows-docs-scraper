PCHANGE_BANDWIDTH_ALLOCATION PchangeBandwidthAllocation;

NTSTATUS PchangeBandwidthAllocation(
  [in]  PVOID _context,
  [in]  HANDLE Handle,
  [in]  PHDAUDIO_STREAM_FORMAT StreamFormat,
  [out] PHDAUDIO_CONVERTER_FORMAT ConverterFormat
)
{...}