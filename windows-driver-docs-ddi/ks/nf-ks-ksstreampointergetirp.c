KSDDKAPI PIRP KsStreamPointerGetIrp(
  [in]            PKSSTREAM_POINTER StreamPointer,
  [out, optional] PBOOLEAN          FirstFrameInIrp,
  [out, optional] PBOOLEAN          LastFrameInIrp
);