HRESULT CreateVolume(
  [in]  VDS_VOLUME_TYPE type,
  [in]  VDS_INPUT_DISK  *pInputDiskArray,
  [in]  LONG            lNumberOfDisks,
  [in]  ULONG           ulStripeSize,
  [out] IVdsAsync       **ppAsync
);