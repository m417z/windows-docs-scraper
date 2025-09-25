PALLOCATE_CAPTURE_DMA_ENGINE PallocateCaptureDmaEngine;

NTSTATUS PallocateCaptureDmaEngine(
  [in]  PVOID _context,
  [in]  UCHAR CodecAddress,
  [in]  PHDAUDIO_STREAM_FORMAT StreamFormat,
  [out] PHANDLE Handle,
  [out] PHDAUDIO_CONVERTER_FORMAT ConverterFormat
)
{...}