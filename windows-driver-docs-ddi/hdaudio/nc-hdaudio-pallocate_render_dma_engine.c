PALLOCATE_RENDER_DMA_ENGINE PallocateRenderDmaEngine;

NTSTATUS PallocateRenderDmaEngine(
  [in]  PVOID _context,
  [in]  PHDAUDIO_STREAM_FORMAT StreamFormat,
  [in]  BOOLEAN Stripe,
  [out] PHANDLE Handle,
  [out] PHDAUDIO_CONVERTER_FORMAT ConverterFormat
)
{...}